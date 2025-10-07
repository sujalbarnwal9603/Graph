#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


// Adjacency Matrix


// Undirected Unweighted Graph

int main(){
    int vertex, edges;
    cin >> vertex>>edges;
    
    vector<vector<bool> >AdjMat(vertex, vector<bool>(vertex,0));
    
    int u,v;
    for(int i=0;i<edges;i++){
        cin >> u>> v;
        AdjMat[u][v]=1;
        AdjMat[v][u]=1;
    }
    
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout << AdjMat[i][j] <<" ";
        }
        cout << endl;
    }
}

// Undirected Weighted Graph

int main(){
    int vertex, edges;
    cin >> vertex>>edges;
    
    vector<vector<int> >AdjMat(vertex, vector<int>(vertex,0));
    
    int u,v, weight;
    for(int i=0;i<edges;i++){
        cin >> u>> v>> weight;
        AdjMat[u][v]=weight;
        AdjMat[v][u]=weight;
    }
    
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout << AdjMat[i][j] <<" ";
        }
        cout << endl;
    }
}


// Directed Unweighted Graph

int main(){
    int vertex, edges;
    cin >> vertex>>edges;
    
    vector<vector<bool> >AdjMat(vertex, vector<bool>(vertex,0));
    
    int u,v;
    for(int i=0;i<edges;i++){
        cin >> u>> v;
        AdjMat[u][v]=1;
    }
    
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout << AdjMat[i][j] <<" ";
        }
        cout << endl;
    }
}

// Directed Weighted Graph

int main(){
    int vertex, edges;
    cin >> vertex>>edges;
    
    vector<vector<int> >AdjMat(vertex, vector<int>(vertex,0));
    
    int u,v, weight;
    for(int i=0;i<edges;i++){
        cin >> u>> v>> weight;
        AdjMat[u][v]=weight;
    }
    
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout << AdjMat[i][j] <<" ";
        }
        cout << endl;
    }
}

