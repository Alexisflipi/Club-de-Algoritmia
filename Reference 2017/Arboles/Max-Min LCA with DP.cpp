#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = (1<<30);

//LCA max/min edge with DP
//Built and query:
//<N * log N, log N>

struct G{
  int n, L;
  int LGMAX;
  vi D;
  vector<vi> P, W;
  vector<vii> ady;
  G(int N) : n(N), ady(N), D(N) {L = log(N) + 10;}

  void add(int a, int b, int w) {
    ady[a].push_back(ii(b, w));
    ady[b].push_back(ii(a, w));
  }

  void dfs(int s, int p, int w, int d) {
    D[s] = d, P[s][0] = p, W[s][0] = w;
    for (auto v: ady[s]) if (v.fst != p)
      dfs(v.fst, s, v.snd, d + 1);
  }

  //p[i][j] -> ancestor 2^i of node j
  void built(int root) {
    P = vector<vi>(n, vi(L,   0));
    W = vector<vi>(n, vi(L, INF));
    dfs(root, 0, INF, 0);
    for (int l = 1; l < L; l++)
      for (int i = 0; i < n; i++)
        P[i][l] = P[P[i][l - 1]][l - 1],
        W[i][l] = min(W[i][l - 1], W[P[i][l - 1]][l - 1]);
  }

  int lca(int u, int v) {
    if (D[u] < D[v]) swap(u, v);
    int r = W[u][0];
    for (int i = L - 1; i >= 0; i--)
      if (D[u] - (1 << i) >= D[v])
        r = min(r, W[u][i]), u = P[u][i];
    if (u == v) return r;
    for (int i = L - 1; i >= 0; i--)
      if (P[u][i] != P[v][i])
        r = min(r, W[u][i]),
        r = min(r, W[v][i]),
        u = P[u][i],
        v = P[v][i];
    return  min(r, min(W[u][0], W[v][0]));
  }
};

int main() {
  int v, e; 
  int a, b, w;
  cin >> v >> e;
  G graph(v);
  for (int i = 0; i < e; i++) {
    cin >> a >> b >> w;
    graph.add(a, b, w);
  }
  graph.built(0);
  cout << graph.lca(6, 4) << "\n";
  return 0;
}

/*
10 9
0 1 4
0 2 10
0 3 8
0 4 300
2 5 40
2 6 20
5 7 7
6 8 0
7 9 25

11 10
0 1 4
0 2 10
0 3 8
0 4 300
2 5 40
2 6 20
5 7 7
6 8 0
7 9 25
8 10 3
*/
