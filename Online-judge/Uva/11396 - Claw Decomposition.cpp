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
  int v;
  while (cin >> v && v) {
    int a, b;
    G graph(v);
    while (cin >> a >> b && a && b)
      graph.connected(--a, --b);
    bool flag = graph.isbipartite();
    (flag) ? cout << "YES\n" : cout << "NO\n";
  }
  return 0;
}
/*
4
1 2
1 3
1 4
2 3
2 4
3 4
0 0
6
1 2
1 3
1 6
2 3
2 5
3 4
4 5
4 6
5 6
0 0
0
*/
