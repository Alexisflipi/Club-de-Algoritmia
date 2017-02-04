#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

//Strongly connected components
// O(V + E)
struct G{
  vector<vi> ady;
  vector<vi> cfc;
  vi num, low, s, visit;
  int n, cont, NC;
  G(int N) : n(N), ady(N), cfc(N), 
  num(N, -1), low(N), visit(N) {}

  void connect(int a, int b) {
    ady[a].push_back(b);
  }

  void tarjan(int u) {
    low[u] = num[u] = NC++;
    s.push_back(u); visit[u] = 1;
    for (auto &v : ady[u]) {
      if (num[v] == -1) tarjan(v);
      if (visit[v]) 
        low[u] = min(low[u], low[v]);
    }
    if (low[u] == num[u]) {
      while (1) {
        int v = s.back(); 
        s.pop_back(); visit[v] = 0;
        cfc[cont].push_back(v);
        if (u == v) break;
      } cont++;
    }
  }
  vector<vi> scc() {
    cont = 0, NC = 0;
    for (int i = 0; i < n; i++)
      if (num[i] == -1) tarjan(i);
    return cfc;
  }
};

int main() {
  return 0;
}
