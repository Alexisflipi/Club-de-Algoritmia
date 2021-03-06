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
  
  vi route(int u, int s) {
    path.clear();
    printPath(u, s);
    return path;
  }
  //Sinlge-Source shortest path (SSSP)
  //Algoritmo Dijkstra
  //Time complexity: O(E * log V)
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
  //Si se requiere longest path, cambiar dist(n, -INF)
  //y la desigualdad de relajacion
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
  //Sinlge-source min longest edge
  vi Dijkstra_minimax(lli s) {
    priority_queue<ii, vector<ii>, greater<ii>> Q;

    vi leap(n, INF);
    leap[s] = -INF;
    
    Q.push(ii(leap[s], s));

    while (!Q.empty()) {
      ii f = Q.top(); Q.pop();
      lli d = f.fst, u = f.snd;
      if (d == INF) break;
      for (auto v : ady[u])
        if (max(d, Dista[u][v.fst]) < leap[v.fst])
          leap[v.fst] = max(d, Dista[u][v.fst]),
          Q.push(ii(leap[v.fst], v.fst));
    }
    return leap;
  }
};

int main() {
  
  return 0;
}
/*

*/
