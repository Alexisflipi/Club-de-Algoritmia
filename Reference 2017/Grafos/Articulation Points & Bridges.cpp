#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// O(V + E)
//Si se requiere saber cuantas componentes 
//conexas hay al quitar un art point solo 
//cambiar a art[u]++ y agregar a todo 1 al final
struct G {
  vector<vi> ady;
  vi num, parent, low, art;
  vii bridge;
  int N;
  G(int n) : N(n), num(n, -1), ady(n, vi()), 
  parent(n), low(n), art(n) {}

  void connect(int a, int b) {
    ady[a].push_back(b);
    ady[b].push_back(a);
  }

  int root, rootChildren, NC;
  void apb(int u) {
    low[u] = num[u] = NC++;
    for (auto v : ady[u]) {
      if (num[v] == -1) {
        parent[v] = u;
        if (u == root) rootChildren++; apb(v);
        if (low[v] >= num[u]) art[u] = 1; 
        //if (low[v] > num[u]) // for bridge
          //bridge.push_back(ii(u, v));
        low[u] = min(low[u], low[v]);
      } else if (v != parent[u])
          low[u] = min(low[u], num[v]);
    }
  }
  vi artpoint() {
    root = 0;
    NC = 0;
    for (int i = 0; i < N; i++)
      if (num[i] == -1) {
        root = i, rootChildren = 0, apb(i);
        art[root] = (rootChildren > 1);
      }
    return art;
  }
};

int main() {
  return 0;
}
