#include <bits/stdc++.h>
using namespace std;

// Autor: Victor Noriega

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

//Max Cardinality Bipartite Match : MCBM
//Nodos indexados 0 ... n - 1
//Lado izq: Nodos pares
//Lado derecho: Nodos impares
//Complejidad: O(V * E)

const int S = -1;

struct Bipartite{
  vb visited, side;
  vector<vi> edges;
  vi couple;
  queue<int> path;
  int n;

  Bipartite(int N):
    n(N), edges(N, vi()), 
    couple(N, S), side(N), visited(N) {}
  
  void addEdge(const int u, const int v){
    edges[u].push_back(v),
    edges[v].push_back(u);
  }

  void setLeft(const int u){
    side[u] = true;
  }

  void setRight(const int v){
    side[v] = false;
  }

  int augmentingPath(const int u){
    visited[u] = true, path.push(u);
    for(int v : edges[u])
      if(couple[v] == S)
        return couple[v] = u;
    for(int v : edges[u]){
      if(visited[couple[v]]) continue;
      if(augmentingPath(couple[v]) != S)
        return couple[v] = u;
    }
    return S;
  }

  vector<ii> maximumMatching(){
    vector<ii> match;
    for(int u = 0; u < n; u++){
      if(!side[u]) continue;
      augmentingPath(u);
      while(!path.empty())
        visited[path.front()] = false,
        path.pop();
    }
    int matching = 0;
    for(int v = 0; v < n; v++)
      if(!side[v] and couple[v] != S)
        matching++, 
        match.push_back(ii(couple[v], v));
    return match;
  }
};
//COJ 1695
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k; cin >> n >> k;
  Bipartite B(2 * n + 5);
  for (int i = 0; i < k; i++) {
    int x, y; cin >> x >> y;
    int a  = 2 * x - 1;
    int b = 2 * y;
    B.addEdge(a - 1, b - 1);
    B.setLeft(a - 1);
    B.setRight(b - 1);
  }
  vector<ii> ans = B.maximumMatching();
  cout << ans.size() << "\n";
}
/*
3 4
1 1
1 3
2 2
3 2
*/
