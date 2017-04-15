#include <bits/stdc++.h>
#define forn(i, n) for (lli i = 0; i < n; i++)
#define fst first
#define snd second
using namespace std;

typedef long long lli;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;
typedef vector<ii> vii;
typedef vector<pair<lli, ii>> viii;

const lli INF = (1LL<<60);

struct UnionFind{
  lli n, sets;
  vi p, r, s;
  UnionFind(lli N) : n(N), sets(N), 
  r(N), s(N, 1), p(N) { 
    while (--N) p[N] = N; 
  }
  lli Find(lli i) {
    return (i == p[i]) ? i : (p[i] = Find(p[i]));
  }
  bool isSameSet(lli i, lli j) {
    return (Find(i) == Find(j));
  }
  void Union(lli i, lli j) {
    lli x = Find(i), y = Find(j);
    if (x == y) return; else sets--;
    (r[x] > r[y]) ? p[y] = x, s[x] += s[y] 
                  : p[x] = y, s[y] += s[x];
    if (r[x] == r[y]) r[y]++;
  }
};

struct G{
  lli n, L;
  lli LGMAX;
  vi D;
  vector<vi> P, W;
  vector<vii> ady;
  G(lli N) : n(N), ady(N), D(N) {L = log(N) + 10;}

  void add(lli a, lli b, lli w) {
    ady[a].push_back(ii(b, w));
    ady[b].push_back(ii(a, w));
  }

  void dfs(lli s, lli p, lli w, lli d) {
    D[s] = d, P[s][0] = p, W[s][0] = w;
    for (auto v: ady[s]) if (v.fst != p)
      dfs(v.fst, s, v.snd, d + 1);
  }

  void built(lli root) {
    P = vector<vi>(n, vi(L,   0));
    W = vector<vi>(n, vi(L, INF));
    dfs(root, 0, INF, 0);
    for (lli l = 1; l < L; l++)
      for (lli i = 0; i < n; i++)
        P[i][l] = P[P[i][l - 1]][l - 1],
        W[i][l] = min(W[i][l - 1], W[P[i][l - 1]][l - 1]);
  }

  lli lca(lli u, lli v) {
    if (D[u] < D[v]) swap(u, v);
    lli r = W[u][0];
    for (lli i = L - 1; i >= 0; i--)
      if (D[u] - (1 << i) >= D[v])
        r = min(r, W[u][i]), u = P[u][i];
    if (u == v) return r;
    for (lli i = L - 1; i >= 0; i--)
      if (P[u][i] != P[v][i])
        r = min(r, W[u][i]),
        r = min(r, W[v][i]),
        u = P[u][i],
        v = P[v][i];
    return  min(r, min(W[u][0], W[v][0]));
  }
};

struct K{
  lli n;
  viii edges;
  K(lli N) : n(N) {}
  
  void connect(lli a, lli b, lli cost) {
    edges.push_back(make_pair(cost, ii(a, b)));
  }

  viii kruskal() {
    UnionFind UF(n);
    viii MST;
    sort(edges.begin(), edges.end());
    lli cost = 0;
    for (auto &e : edges) {
      lli w = e.fst;
      lli a = e.snd.fst;
      lli b = e.snd.snd;
      if (!UF.isSameSet(a, b)) {
        MST.push_back(e);
        cost += w;
        UF.Union(a, b);
      }
    }
    return MST;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  lli n, m, s;
  while (cin >> n >> m >> s) {
    K *graph = new K(n);
    forn(i, m) {
      lli a, b, w;
      cin >> a >> b >> w;
      graph -> connect(--a, --b, -w);
    }
    viii mst = graph -> kruskal();
    G *tree = new G(n);
    for (auto &e : mst)
      tree -> add(e.snd.fst, e.snd.snd, -e.fst);
    tree -> built(0);
    forn(i, s) {
      lli a, b;
      cin >> a >> b;
      cout << tree -> lca(--a, --b) << '\n';
    }
    delete graph;
    delete tree;
  }
  return 0;
}
/*
4 5 4
1 2 9
1 3 0
2 3 8
2 4 7
3 4 4
1 4
2 1
3 1
4 3
4 5 2
1 2 30
2 3 20
3 4 10
4 1 40
2 4 50
1 3
1 2
*/
