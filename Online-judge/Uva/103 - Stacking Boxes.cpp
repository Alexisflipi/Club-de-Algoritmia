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
  vi p, path, ts, visit;
  G(int N) : n(N), ady(N), p(N), visit(N, 0) {}

  void connect(int a, int b, int costo) {
    ady[a].push_back(ii(b, costo));
  }

  //Imprime el camino de cualquier nodo v al nodo s -> printPath(v, s)
  void printPath(int u, int s) {
    if (u == s) { path.push_back(s); return; }
    printPath(p[u], s); 
    path.push_back(u);
  }

  vi route(int u, int s) {
    path.clear();
    printPath(u, s);
    return path;
  }

  void dfs(int u) {
    visit[u] = 1;
    for (auto &v : ady[u])
      if (!visit[v.fst]) dfs(v.fst);
    ts.push_back(u);
  }

  void rundfs() {
    for (int i = 0; i < n; i++)
      if (!visit[i]) dfs(i);
    reverse(ts.begin(), ts.end());
  }
  //Dijkstra O(V + E)
  //Sólo funciona con DAG usando topological sort
  //Si se requiere longest path, cambiar dist(n, -INF)
  //y la desigualdad de relajacion
  vi Dijkstra_lineal(int s) {
    //El vector ts contiene el orden topológico
    rundfs();
    vi dist(n, -INF);
    dist[s] = 0;
    for (auto &u : ts)
      for (auto &v : ady[u])
        if (dist[u] + v.snd > dist[v.fst])
          dist[v.fst] = dist[u] + v.snd, p[v.fst] = u;
    return dist;
  }
};

G built(map<int, pair<vi, int>> &boxes, int k, int n) {
  G graph(k + 2);
  for (int i = 0; i < k; i++)
    for (int j = i + 1; j < k; j++) {
      int f = 1;
      vi a = boxes[i + 1].fst;
      vi b = boxes[j + 1].fst;
      for (int k = 0; k < n; k++)
        if (a[k] < b[k]) f = 1; else {f = 0; break;}
      if (f)
        graph.connect(boxes[i + 1].snd, boxes[j + 1].snd, 1);
    }
  for (int i = 0; i < k; i++)
    graph.connect(0, i + 1, 0), 
    graph.connect(i + 1, k + 1, 0);
  return graph;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int k, n, a; 
  while (cin >> k >> n) {
    set<pair<vi, int>> box;
    map<int, pair<vi, int>> m_box;
    vector<vi> bus(k + 2);
    for (int i = 0; i < k; i++)
      for (int j = 0; j < n; j++)
        cin >> a, bus[i + 1].push_back(a);

    for (int i = 0; i < k; i++) 
      sort(bus[i + 1].begin(), bus[i + 1].end()), 
    box.insert(make_pair(bus[i + 1], i + 1));
    int cont = 0;
    for (auto &b : box)
      m_box[++cont] = b;

    G graph = built(m_box, k, n);
    vi ans = graph.Dijkstra_lineal(0);
    vi f = graph.route(k + 1, 0);
    cout << f.size() - 2 << "\n";
    for (int i = 1; i < f.size() - 2; i++)
      cout << f[i] << " ";
    cout << f[f.size() - 2] << "\n";
  }

  return 0;
}
/*
5  2
3  7
8  10
5  2
9  11
21  18
8  6
5  2  20  1  30  10
23  15  7  9  11  3
40  50  34  24  14  4
9  10  11  12  13  14
31  4  18  8  27  17
44  32  13  19  41  19
1  2  3  4  5  6
80  37  47  18  21  9
*/
