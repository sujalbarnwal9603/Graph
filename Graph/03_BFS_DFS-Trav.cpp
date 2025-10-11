#include <bits/stdc++.h>
using namespace std;

// Breadth First Search

// TC=O(V+2E) = O(V+E)
// SC=O(V) + O(V) = O(2V) = O(V)


// you will be given a graph in the form of adjacency list and you have to return the BFS traversal of the graph starting from 0.
vector<int> BFSGraph(int v, vector<int> adj[]){
  queue<int> q;
  vector<bool> visited(v,0);
  q.push(0);
  visited[0]=1;
  vector<int> ans;
  while(!q.empty()){
    int node=q.front();
    q.pop();
    ans.push_back(node);
    for(int j=0;j<adj[node].size();j++){
      if(!visited[adj[node][j]]){
        q.push(adj[node][j]);
        visited[adj[node][j]]=1;
      }
    }
  }
  return ans;
}


// Depth First Search

// TC=O(V+2E) = O(V+E)
// SC=O(V) + O(V) = O(2V) = O(V)


void DFS(int node, vector<int> adj[],vector<bool>&visited, vector<int>&ans){
  visited[node]=1;
  ans.push_back(node);
  for(int j=0;j<adj[node].size();j++){
    if(!visited[adj[node[j]]]){
      DFS(adj[node][j],adj,visited,ans);
    }
  }
}

int main(){
    return 0;
}