#inclulde <iostream>
#include <vector>
#include <climits>
using namespace std;
struct Node{
  int key;
  int val;
  Node(int v, int w);
};
Node::Node(int v, int w){
  key = v;
  val = w;
}
int main(){
  int V, E, u, v, w;
  cin >> V >> E;
  vector<Node> *graph;
  graph = new vector<Node>[V];
  vector<int> distance(V,INT_MAX);
  distance[0] = 0;
  for(int i = 0; i < E; i++){
    cin >> u >> v >> w;
    graph[u].push_back(Node(v,w));
  }
//Constr Done
  for(int i = 1; i < V; i++){
    for(int j = 0; j < V; j++){
      for(int k = 0; k < graph[j].size(); k++){
        u = j;
        v = graph[j][k].key;
        w = graph[j][k].val;
      if(distance[u] != INT_MAX && distance[v] > distance[u] + w)
        distance[v] = distance[u] + w;
  } } }
  for(int j = 0; j < V; j++){
    for(int k = 0; k < graph[j].size(); k++){
      u = j;
      v = graph[j][k].key;
      w = graph[j][k].val;
    if(distance[u] != INT_MAX && distance[v] > distance[u] + w){
      cout << "FALSE" << endl;
      return -1;
  } } }
//Print
  cout << "TRUE" << endl;
  for(int i = 0; i < distance.size(); i++)
    if(distance[i] == INT_MAX)
      cout << "INFINITY" << endl;
    else
      cout<< distance[i] << endl;
}
