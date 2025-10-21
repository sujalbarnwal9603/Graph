#include <bits/stdc++.h>
using namespace std;


// Topological Sort using DFS


void DFS(int node, vector<int>adj[], vector<int>&visited, stack<int>&st){
    visited[node]=1;
    //look its negihbour
    for(int j=0;j<adj[node].size();j++){
        if(!visited[adj[node][j]]){
            DFS(adj[node][j],adj,visited,st);
        }
        st.push(node);
    }
}

vector<int> topoSort(int V, vector<int>adj[]){
    vector<int> visited(V,0);
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            DFS(i,adj,visited,st);
        }
    }
    vector<int> result;
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }
    return result;    
}



// Topological Sort using BFS (Kahn's Algorithm)

vector<int> topoSortBFS(int V, vector<int> adj[]){
    vector<int> ans;
    vector<int>InDeg(V,0);

    //calculate indegree
    for(int i=0;i<V;i++){
        for(int j=0;j<adj[i].size();j++){
            InDeg[adj[i][j]]++;
        }
    }
    queue<int> q;
    //push all nodes with indegree 0
    for(int i=0;i<V;i++){
        if(InDeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        //reduce indegree of its neighbour
        for(int j=0;j<adj[node].size();j++){
            InDeg[adj[node][j]]--;
            if(InDeg[adj[node][j]]==0){
                q.push(adj[node][j]);
            }
        }
    }
    return ans;
}