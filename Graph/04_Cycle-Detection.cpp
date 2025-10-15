#include <bits/stdc++.h>
using namespace std;


// DFS
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

    /*** DFS
    // vector<vector<int>> adj;
    // int V=5;
    // vector<bool> visited(V,0);
    // cout << isCycle(adj,0,-1,visited);
    
    ***/


    return 0;
}