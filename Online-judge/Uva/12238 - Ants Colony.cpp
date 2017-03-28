#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

//LCA with DP
//Built and query:
//<N * log N, log N>

struct G{
  vector<vi> p;
  vector<vii> ady;
  vi d, visit, dist;
  int LGMAX;
  int n;
  G(int N) : n(N), ady(N), d(N), 
  visit(N), dist(N) {LGMAX = log(N) + 10;}

  void add(int a, int b, int w) {
    ady[a].push_back(ii(b, w));
    ady[b].push_back(ii(a, w));
  }

  void dfs(int u) {
    visit[u] = 1;
    for (auto v : ady[u])
      if (!visit[v.fst]) 
        p[0][v.fst] = u, 
        d[v.fst] = d[u] + 1, 
        dist[v.fst] = dist[u] + v.snd, dfs(v.fst);
  }

  void built(int root) {
    //p[i][j] -> ancestor 2^i of node j
    p = vector<vi>(LGMAX, vi(n, -1));
    dfs(root);
    for (int i = 1; i < LGMAX; i++)
      for (int j = 0; j < n; j++)
        if (p[i - 1][j] != -1)
          p[i][j] = p[i - 1][p[i - 1][j]];
  }
  //Jump for the nodes that have the same level
  int getparent(int u, int k) {
    for (int i = 0; i < LGMAX; i++) {
      if (k & 1) u = p[i][u];
      k >>= 1;
    }
    return u;
  }

  int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    u = getparent(u, d[u] - d[v]);
    if (u == v) return u;
    for (int i = LGMAX - 1; i >= 0; i--) 
      if (p[i][u] != p[i][v])
        u = p[i][u], v = p[i][v];
    //parent of u or v is now the lca
    return p[0][u];
  }

  int query(int a, int b) {
    return dist[a] + dist[b] - 2 * dist[lca(a, b)];
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  while (cin >> n && n) {
    G graph(n);
    for (int i = 0; i < n - 1; i++) {
      int a, w; cin >> a >> w;
      graph.add(i + 1, a, w);
    }
    vi ans;
    graph.built(0);
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
      int a, b; cin >> a >> b;
      ans.push_back(graph.query(a, b));
    }
    for (int i = 0; i < ans.size() - 1; i++)
      cout << ans[i] << " ";
    cout << ans[ans.size() - 1]<< "\n";
  }
  return 0;
}
/*
6
0 8
1 7
1 9
0 3
4 2
4
2 3
5 2
1 4
0 3
*/
