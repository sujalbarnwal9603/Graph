#include <bits/stdc++.h>
using namespace std;


// DFS
//steps for dfs cycle detection in undirected graph
//1. create a visited array to keep track of visited nodes
//2. for each unvisited node, call the recursive function isCycle
//3. in isCycle function, mark the current node as visited
//4. for each neighbour of the current node, if it is not visited, recursively call isCycle
//5. if the neighbour is visited and is not the parent of the current node, then a cycle is detected    


bool isCycle(vector<vector<int>>&adj,int node, int parent, vector<int>&visited){
    visited[node]=1;
    for(int j=0;j<adj[node].size();j++){
        if(parent==adj[node][j]) continue;
        if(visited[adj[node][j]]==1) return 1;
        if(isCycle(adj,adj[node][j],node,visited)){
            return 1;
        }
    }
    return 0;
}

int main(){

    //  DFS
    vector<vector<int>> adj;
    int V=5;
    vector<bool> visited(V,0);
    for(int i=0;i<V;i++){
        if(!visited[i] && isCycle(adj,i,-1,visited)){
            cout<<"Cycle is present"<<endl;
            return 1;
        }
    }

    return 0;
}


// BFS
//steps for bfs cycle detection in undirected graph
//1. create a visited array to keep track of visited nodes
//2. for each unvisited node, call the BFS function
//3. in BFS function, use a queue to perform level order traversal
//4. for each neighbour of the current node, if it is not visited, mark it as visited and push it to the queue with current node as parent
//5. if the neighbour is visited and is not the parent of the current node, then a cycle is detected

bool BFS(int vertex, vector<int>adj, vector<bool>&visited){
    queue<pair<int,int>>q;
    visited[vertex]=1;
    q.push(make_pair{vertex,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(int j=0;j<adj[node].size();j++){
            if(parent==adj[node][j]) continue;
            if(visited[adj[node][j]]){
                return 1;
            }
            visited[adj[node][j]]=1;
            q.push(make_pair{adj[node][j],node});
        }
    }
    return 0;
}

bool isCycleBFS(vector<vector<int>>&adj,int V){
    vector<bool> visited(V,0);
    for(int i=0;i<V;i++){
        if(!visited[i] && BFS(i, adj,visited)){
            return 1;
        }
    }
    return 0;
}
int main(){

    // BFS
    vector<vector<int>> adj;
    int V=5;
    if(isCycleBFS(adj,V)){
        cout<<"Cycle is present"<<endl;
        return 1;
    }

    return 0;
}
//Tc: O(V+E)
//Sc: O(V) for visited array and O(V) for recursive stack in DFS or O(V) for queue in BFS
