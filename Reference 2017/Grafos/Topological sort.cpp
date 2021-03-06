#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = (1 << 30);

struct G{
  int n;
  vector<vii> ady;
  vi p, path;
  G(int N) : n(N), ady(N), p(N) {}

  void connect(int a, int b, int costo) {
    ady[a].push_back(ii(b, costo));
  }

  //Imprime el camino de cualquier nodo v al nodo s -> printPath(v, s)
  void printPath(int u, int s) {
    if (u == s) { path.push_back(s); return; }
    printPath(p[u], s); 
    path.push_back(u);
  }

  vi Dijkstra(int s) {
    vi dist(n, INF);
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push(ii(0, s));
    dist[s] = 0;
    while (!Q.empty()) {
      ii f = Q.top(); Q.pop();
      int d = f.fst, u = f.snd;
      if (d > dist[u]) continue;
      for (auto v : ady[u])
        if (dist[u] + v.snd < dist[v.fst]) { // Relaja arista
          dist[v.fst] = v.snd + dist[u]; 
          Q.push(ii(dist[v.fst], v.fst));
          p[v.fst] = u; //reconstruir el camíno mínimo
        }
    }
    return dist;
  }
  //Dijkstra O(V + E)
  //Sólo funciona con DAG usando topological sort
  vi Dijkstra_lineal(int s) {
    //El vector ts contiene el orden topológico
    vi dist(n, INF);
    dist[s] = 0;
    for (auto &u : ts)
      for (auto &v : ady[u])
        if (dist[u] + v.snd < dist[v.fst])
          dist[v.fst] = dist[u] + v.snd, p[v.fst] = u;
    return dist;
  }
};

vi indegree; 
vi ts; 
vi grafo[MAX];  
//toposort with in-degree, only DAG
void kahn(int N){  
  priority_queue<int, vector<int>, greater<int>> Q;
  for (int i = 0; i < N; i++)   
    if (indegree[i] == 0) Q.push(i);
  while (!Q.empty()){   
    int u = Q.top(); Q.pop();   
    ts.push_back(u);   
    for (auto v : grafo[u]){   
      indegree[v]--;   
      if (indegree[v] == 0) Q.push(v);   
    }  
  } 
}

int main() {
  
  return 0;
}
/*
*/
