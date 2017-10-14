#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;
int V, E;
struct Graph{
  vector<int> *adj;
  Graph(int V);
};
Graph::Graph(int V){
  adj = new vector<int>[V];
}
void tDFS(Graph graph, int v, bool visited[], int *SCC, int *min){
  if(visited[v] == false){
    visited[v] = true;
    if(v < *min)
      *min = v;
    for(int i = 0; i < graph.adj[v].size(); i++){
      int nextv = graph.adj[v][i];
      tDFS(graph, nextv, visited, SCC, min);
    }
    SCC[v] = *min;
  }
}
void DFS(Graph graph, int v, bool visited[], stack<int> &Stack){
  if(visited[v] == false){
    visited[v] = true;
    for(int i = 0; i < graph.adj[v].size(); i++){
      int nextv = graph.adj[v][i];
      DFS(graph, nextv, visited, Stack);
    }
    Stack.push(v);
  }
}
int main(){
  int u, v;
  cin >> V >> E;
  Graph graph(V);
  for(int i = 0; i < E; i++){
    cin >> u >> v;
    graph.adj[u].push_back(v);
  }
  stack<int> Stack;
  bool *visited = new bool[V];
  for(int i = 0; i < V; i++)
    visited[i] = false;
  for(int i = 0; i < V; i++)
    DFS(graph, i, visited, Stack);
//Trans
  Graph graphT(V);
  for (int i = 0; i < V; i++){
     for(int j = 0; j < graph.adj[i].size(); j++){
       graphT.adj[graph.adj[i][j]].push_back(i);
  }  }

  for(int i = 0; i < V; i++)
    visited[i] = false;
  int *SCC = new int[V];
  for(int i = 0; i < V; i++)
    SCC[i] = 0;
  int mem;
  int *min = &mem;
  while (Stack.empty() == false){
    *min = INT_MAX;
    int v = Stack.top();
    Stack.pop();
    if (visited[v] == false){
      tDFS(graphT, v, visited, SCC, min);
    }
  }
  for(int i = 0; i < V; i++)
    cout << SCC[i] << endl;
}

