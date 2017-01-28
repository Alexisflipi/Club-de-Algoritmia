#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int A = 100;
const int B = 7;
const int INF = (1 << 30);
int m[B][A];

struct G{
  int n;
  vector<vii> ady;
  vi p, path;
  G(int N) : n(N), ady(N), p(N) {}

  void connect(int a, int b, int costo) {
    ady[a].push_back(ii(b, costo));
    ady[b].push_back(ii(a, costo));
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
      for (auto v : ady[u]) {
        if (dist[u] + v.snd < dist[v.fst]) { // Relaja arista
          dist[v.fst] = v.snd + dist[u]; 
          Q.push(ii(dist[v.fst], v.fst));
          p[v.fst] = u; //reconstruir el camíno mínimo
        }
      }
    }
    return dist;
  }
};

int built(vi t, vector<vi> e, int k) {
  int n = t.size();
  int node = 0;
  G graph(A * B);
  map<ii, int> mapeo;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < e[i].size() - 1; j++) {
      ++node;
      int a = e[i][j];
      int b = e[i][j + 1];
      graph.connect(node, node + 1, t[i] * (b - a));
      mapeo[ii(i, a)] = node;
    }
    node++;
    mapeo[ii(i, e[i][e[i].size() - 1])] = node;
  }
  vi source;
  for (int j = 0; j < A; j++) {
    for (int i = 0; i < n; i++) {
      if (m[i][j] && j == 0)
        source.push_back(mapeo[ii(i, j)]);

      for (int k = i + 1; k < n; k++)
        if (m[i][j] && m[k][j])
          graph.connect(mapeo[ii(i, j)], mapeo[ii(k, j)], 60);
    }
  }
  int mini = INF;
  for (auto it : source) {
    vi ans = graph.Dijkstra(it);
    for (int i = 0; i < n; i++) {
      if (m[i][k])
        mini = min(mini, ans[mapeo[ii(i, k)]]);
    }
  }
  return mini;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  while (cin >> n >> k) {
    vi t(n);
    vector<vi> e(n);
    for (int i = 0; i < n; i++)
      cin >> t[i];
    cin.ignore();
    string s;
    for (int i = 0; i < n; i++) {
      getline(cin, s);
      stringstream ss(s);
      string aux;
      while (ss >> aux) {
        e[i].push_back(atoi(aux.c_str()));
        m[i][atoi(aux.c_str())] = 1;
      }
    }
    int ans = built(t, e, k);
    if (ans == INF)
      cout << "IMPOSSIBLE\n";
    else
      cout << ans << "\n";
    memset(m, 0, sizeof m);
  }
  return 0;
}
/*
2 30
10 5
0 1 3 5 7 9 11 13 15 20 99
4 13 15 19 20 25 30
2 30
10 1
0 5 10 12 14 20 25 30
2 4 6 8 10 12 14 22 25 28 29
3 50
10 50 100
0 10 30 40
0 20 30
0 20 50
1 1
2
0 2 4 6 8 10
*/
