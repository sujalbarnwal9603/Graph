#include <iostream>
#include <vector>

using namespace std;


// undirected Unweighted Graph

int main() 
{
    int vertex, edges;
    cin >> vertex>> edges;
    
    vector<int> AdjList[vertex];
    
    int u, v;
    for(int i=0;i<edges;i++){
      cin>>u>>v;
      AdjList[u].push_back(v);
      AdjList[v].push_back(u);
    }
    
    // PRint the list
    
    for(int i=0;i<vertex;i++){
      cout << i <<"->";
      for(int j=0;j<AdjList[i].size();j++){
        cout << AdjList[i][j]<<" ";
      }
      cout << endl;
    }
}


// undirected Weighted Graph

#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int vertex, edges;
    cin >> vertex>> edges;
    
    vector<pair<int,int>> AdjList[vertex];
    
    int u, v, weight;
    for(int i=0;i<edges;i++){
      cin>>u>>v>> weight;
      AdjList[u].push_back({v,weight});
      AdjList[v].push_back({u,weight});
    }
    
    // PRint the list
    
    for(int i=0;i<vertex;i++){
      cout << i <<"->";
      for(int j=0;j<AdjList[i].size();j++){
        cout << AdjList[i][j].first<<" "<< AdjList[i][j].second<<" ";
      }
      cout << endl;
    }
}


// directed Unweighted Graph

#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int vertex, edges;
    cin >> vertex>> edges;
    
    vector<int> AdjList[vertex];
    
    int u, v;
    for(int i=0;i<edges;i++){
      cin>>u>>v;
      AdjList[u].push_back(v);
    }
    
    // PRint the list
    
    for(int i=0;i<vertex;i++){
      cout << i <<"->";
      for(int j=0;j<AdjList[i].size();j++){
        cout << AdjList[i][j]<<" ";
      }
      cout << endl;
    }
}



// directed Weighted Graph


#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int vertex, edges;
    cin >> vertex>> edges;
    
    vector<pair<int,int>> AdjList[vertex];
    
    int u, v, weight;
    for(int i=0;i<edges;i++){
      cin>>u>>v>> weight;
      AdjList[u].push_back({v,weight});
    }
    
    // PRint the list
    
    for(int i=0;i<vertex;i++){
      cout << i <<"->";
      for(int j=0;j<AdjList[i].size();j++){
        cout << AdjList[i][j].first<<" "<< AdjList[i][j].second<<" ";
      }
      cout << endl;
    }
}