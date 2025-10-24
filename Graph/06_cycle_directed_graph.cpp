#include <bits/stdc++.h>
using namespace std;

// DFS
//steps for dfs cycle detection in directed graph
//1. create a visited array to keep track of visited nodes
//2. create a recursion stack array to keep track of nodes in the current recursion stack
//3. for each unvisited node, call the recursive function isCycle
//4. in isCycle function, mark the current node as visited and add it to the
//   recursion stack
//5. for each neighbour of the current node, if it is not visited, recursively call
//   isCycle
//6. if the neighbour is in the recursion stack, then a cycle is detected


bool DetectCycleDFS(int Node, vector<int>adj[], vector<bool>&path, vector<bool>&visited){
    path[Node]=1;
    for(int j=0;j<adj[Node].size();j++){

        //if neighbour is in current path, cycle is detected
        if(path[adj[Node][j]]) return 1;

        //if neighbour is already visited and not in current path, skip it

        if(visited[adj[Node][j]]) continue;

        
        if(DetectCycleDFS(adj[Node][j],adj,path,visited)){
            return 1;
        
        }
    }
    path[Node]=0;
    return 0;
}

bool isCycle(vector<int>adj[], int V){
    vector<bool>visited(V,0);
    vector<bool>path(V,0);

    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(DetectCycleDFS(i,adj,path,visited)){
                return 1;
            }
        }
    }
    return 0;
}



//BFS
//steps for bfs cycle detection in directed graph using Kahn's Algorithm
//1. create an indegree array to keep track of indegrees of all nodes
//2. calculate indegrees of all nodes
//3. create a queue and push all nodes with indegree 0
//4. perform bfs traversal, for each node, reduce the indegree of its neighbours by 1
//5. if the indegree of any neighbour becomes 0, push it to the queue
//6. keep track of the count of nodes visited
//7. if the count of nodes visited is not equal to the number of nodes, then a cycle is detected    


bool isCyclic(int V, vector<int> adj[]){
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
        for(int j=0;j<adj[i].size();j++){
            indegree[adj[i][j]]++;
        }
    }

    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    int count=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        count++;
        for(int j=0;j<adj[node].size();j++){
            indegree[adj[node][j]]--;
            if(indegree[adj[node][j]]==0){
                q.push(adj[node][j]);
            }
        }
    }

    if(count!=V) return 1;
    return 0;
}