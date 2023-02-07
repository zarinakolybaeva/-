#include <bits/stdc++.h>
using namespace std;
class Graph {
  int numVertices;
  list<int>* adjLists;
  bool* visited;

   public:
  Graph(int vertices);
  void addEdge(int src, int dest);
  void bfs(int startVertex,int x,int y);
};

Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
}

void Graph::addEdge(int src, int dest) {
  adjLists[src].push_back(dest);
  adjLists[dest].push_back(src);
}

void Graph::bfs(int startVertex,int x,int y) {
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);
  int cnt = 0;
  list<int>::iterator i;

  while (!queue.empty()) {
    int currVertex = queue.front();
    if(currVertex == x or currVertex == y) cnt++;
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
      int adjVertex = *i;
      if (!visited[adjVertex]) {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
  if(cnt == 2) cout<<"YES";
  else cout<<"NO";
}
 

int main(){
    int n,m;
    
    cin>>n>>m; 
    Graph g(n+1);
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        g.addEdge(x,y);
    }
    cin>>x>>y;
    g.bfs(x,x,y);   
}