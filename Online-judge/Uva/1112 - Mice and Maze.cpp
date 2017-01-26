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
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    if (i > 0) cout << "\n";
    int n, e, ti, m;
    cin >> n >> e >> ti >> m;
    G graph(n);
    for (int i = 0; i < m; i++) {
      int a, b, w; cin >> a >> b >> w;
      graph.connect(--a, --b, w);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      vi d = graph.Dijkstra(i);
      if (d[e - 1] <= ti) ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}
/*
1
4
2
1
8
1 2 1
1 3 1
2 1 1
2 4 1
3 1 1
3 4 1
4 2 1
4 3 1

*/
