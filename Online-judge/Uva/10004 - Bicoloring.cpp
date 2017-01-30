#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct G{
  int n;
  vector<vi> ady;
  vi color, visit;
  G(int N) : n(N), ady(N), color(N, -1), visit(N) {}

  void connected(int a, int b) {
    ady[a].push_back(b);
    ady[b].push_back(a); //Si es bidireccional
  }

  bool dfs(int u, int c) {
    color[u] = c, visit[u] = 1;
    bool ans = 1;
    for (auto &v : ady[u])
      if (!visit[v]) ans &= dfs(v, (c + 1) % 2);
      else if (color[u] == color[v]) return 0;
    return ans;
  }

  bool isbipartite() {
    bool ans = 1;
    for (int i = 0; i < n; i++)
      if (!visit[i]) ans &= dfs(i, 0);
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  int a, b;
  while (cin >> n && n) {
    int e; cin >> e;
    G graph(n);
    for (int i = 0; i < e; i++)
      cin >> a >> b, graph.connected(a, b);
    (graph.isbipartite()) ? cout << "BICOLORABLE.\n" : cout << "NOT BICOLORABLE.\n";
  }
  return 0;
}

/*
3
3
0 1
1 2
2 0
3
2
0 1
1 2
9
8
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8
0
*/
