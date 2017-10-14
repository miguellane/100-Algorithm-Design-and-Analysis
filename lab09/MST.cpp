#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
using namespace std;

void MST(vector<vector<int> > graph, int *parent){
  int V = graph.size();
  int u , min;
  vector<int> keys(V,INT_MAX);
  vector<bool> mstSet(V, false);
  keys[0] = 0;
  for (int i = 0; i < V-1; i++){
    min = INT_MAX;
    for (int j = 0; j < V; j++)
      if (mstSet[j] == false && keys[j] < min){
        min = keys[j];
        u = j;
    }
    mstSet[u] = true;
    for (int v = 0; v < V; v++)
      if (graph[u][v] && mstSet[v] == false && graph[u][v] <  keys[v]){
        parent[v]  = u;
        keys[v] = graph[u][v];
      }
   }
}

int main(){
  int V, E, u, v, w;
  cin >> V >> E;
  vector< vector<int> > graph(V, vector<int>(V,0));
  for(int i = 0; i < E; i++){
    cin >> u >> v >> w;
    graph[u][v] = w;
    graph[v][u] = w;
  }
  int *parent = new int[V];
  MST(graph, parent);
  for (int i = 1; i < V; i++)
      cout << parent[i] << endl;
 }
