#include <bits/stdc++.h>
using namespace std;

const int MAX = 500;

//  Maximum flow. 
//  Dinic's algorithm in O(V^2 * E)

typedef vector<int> vi;

struct Edge {
  int to, rev;
  int f, cap;
};

struct MF{
  vector<vector<Edge> > g;
  vi dist, q, work;
  int src, dest, nodes;

  MF(int n) : nodes(n), dist(n), q(n), work(n), g(n) {}
  
  // Adds bidirectional edge
  void addEdge(int s, int t, int cap){
    Edge a = {t, g[t].size(), 0, cap};
    Edge b = {s, g[s].size(), 0, cap};
    g[s].push_back(a);
    g[t].push_back(b);
  }

  bool dinic_bfs() {
    dist.assign(nodes, -1);
    dist[src] = 0;
    int qt = 0;
    q[qt++] = src;
    for (int qh = 0; qh < qt; qh++) {
      int u = q[qh];
      for (int j = 0; j < (int) g[u].size(); j++) {
        Edge &e = g[u][j];
        int v = e.to;
        if (dist[v] < 0 && e.f < e.cap) {
          dist[v] = dist[u] + 1;
          q[qt++] = v;
        }
      }
    }
    return dist[dest] >= 0;
  }

  int dinic_dfs(int u, int f) {
    if (u == dest)
      return f;
    for (int &i = work[u]; i < (int) g[u].size(); i++) {
      Edge &e = g[u][i];
      if (e.cap <= e.f) continue;
      int v = e.to;
      if (dist[v] == dist[u] + 1) {
        int df = dinic_dfs(v, min(f, e.cap - e.f));
        if (df > 0) {
          e.f += df;
          g[v][e.rev].f -= df;
          return df;
        }
      }
    }
    return 0;
  }

  int maxFlow(int _src, int _dest) {
    src = _src;
    dest = _dest;
    int result = 0;
    while (dinic_bfs()) {
      work.assign(nodes, 0);
      while (int delta = dinic_dfs(src, INT_MAX))
        result += delta;
    }
    return result;
  }
};

int capacity[MAX][MAX];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; int net = 0;
  while (cin >> n and n) {
    int s, t, m;
    MF *graph = new MF(n);
    cin >> s >> t >> m;
    for (int i = 0; i < m; i++) {
      int a, b, w;
      cin >> a >> b >> w;
      graph -> addEdge(--a, --b, w);
      graph -> addEdge(b, a, w);
    }
    int ans = (graph -> maxFlow(--s, --t))/2;
    cout << "Network " << ++net << "\n";
    cout << "The bandwidth is " << ans << ".\n\n";
  }
  
}
/*
4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
3
1 3 3
1 2 3
2 3 2
1 3 2
0
*/
