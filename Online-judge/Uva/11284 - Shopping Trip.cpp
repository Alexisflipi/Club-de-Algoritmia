#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef int d;
typedef pair<int, d> id;
typedef vector<id> vid;
typedef vector<d> vd;
const d INF = d(1<<25);
const int MAX = 20;

struct G{
  int n;
  vector<vd > m;
  G(int N) : n(N), m(N, vd(N, INF)) {}

  void add(int a, int b, d w) {
    m[a][b] = m[b][a] = min(m[a][b], w);
  }

  void Floyd() {
    for (int i = 0; i < n; i++) 
      m[i][i] = 0.0;
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
  }
  d query(int a, int b) {
    return m[a][b];
  }
};

map<int, d> mapeo;
d dist[MAX][MAX];
d memo[MAX][10000];
int n;

void makeset(int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dist[i][j] = INF;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 10000 - 3; j++)
      memo[i][j] = -1;
}

void built(vid dvd, G *g) {
  n = dvd.size();
  makeset(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      auto u = dvd[i];
      auto v = dvd[j];
      dist[i][j] = min(dist[i][j], g -> query(u.fst, v.fst));
    }
  }
}

d tsp(int idx, int mask) {
  if (mask == (1<<n) - 1)
    return -dist[idx][0];
  if (memo[idx][mask] != -1)
    return memo[idx][mask];
  d ans = tsp(idx, (1<<n) - 1);
  for (int i = 0; i < n; i++) {
    if (mask & (1<<i) || idx == i) continue;
    ans = max(ans, mapeo[i] - dist[idx][i] + tsp(i, mask|(1<<i)));
    ans = max(ans, 0 + tsp(idx, mask|(1<<i)));
  }
  return memo[idx][mask] = ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--) {
    int v, e;
    cin >> v >> e;
    G *graph = new G(v + 1);
    for (int i = 0; i < e; i++) {
      int a, b; char p; d w1, w2;
      cin >> a >> b >> w1 >> p >> w2;
      graph -> add(a, b, (w1 * 100 + w2));
    }
    int q; cin >> q;
    vid dvd;
    mapeo[0] = 0;
    dvd.push_back(id(0, 0));
    for (int i = 0; i < q; i++) {
      int node; char p; d cost1, cost2;
      cin >> node >> cost1 >> p >> cost2;
      dvd.push_back(id(node, cost1 * 100 + cost2));
      mapeo[i + 1] = cost1 * 100 + cost2;
    }
    graph -> Floyd();
    built(dvd, graph);
    cout << fixed << setprecision(2);
    d ans = tsp(0, 1);
    if (ans > 0)
      cout << "Daniel can save $" << double(ans)/100.0 << '\n';
    else
      cout << "Don't leave the house\n";
    delete graph;
    mapeo.clear();
  }
  return 0;
}
/*
2
4 5
0 1 1.00
1 2 3.00
1 3 2.00
2 4 4.00
3 4 3.25
3
2 1.50
3 7.00
4 9.00
1 1
0 1 1.50
1
1 2.99

*/
