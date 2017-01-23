#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

const int INF = (1 << 30);

struct G{
  int n;
  vector<vi> ady;
  G(int N) : n(N), ady(N) {}

  void connect(int a, int b) {
    ady[a].push_back(b);
  }

  vi bfs(int s) {
    vi dist(n, INF);
    queue<int> Q; Q.push(s); dist[s] = 0;
    while (!Q.empty()) {
      int u = Q.front(); Q.pop();
      for (auto &v : ady[u])
        if (dist[v] == INF)
          dist[v] = dist[u] + 1, Q.push(v);
    }
    return dist;
  }
};

G build(int n) {
  G graph(n);
  for (int i = 0; i < n; i++) {
    int m; cin >> m;
    for (int j = 0; j < m; j++) {
      int r; cin >> r; graph.connect(i, r);     
    }
  }
  return graph;
}

void solve(vi q, G &graph) {
  for (auto &r : q) {
    int maxi = -INF;
    int day = 0;
    vi ans = graph.bfs(r);
    map<int, int> bus;
    for (auto &c : ans)
      if (c != INF && c != 0) bus[c]++;
    
    for (auto &it : bus) {
      if (it.second > maxi)
        maxi = it.second, day = it.first;
    }
    if (bus.empty() || day == 0)
      cout << "0\n";
    else
      cout << maxi << " " << day << "\n";
  }
}

int main() {
  int n;
  cin >> n;
  G graph = build(n);
  int q; cin >> q;
  vi query(q);
  for (int i = 0; i < q; i++)
    cin >> query[i];
  solve(query, graph);
  return 0;
}
/*
6
2 1 2
2 3 4
3 0 4 5
1 4
0
2 0 2
3
0
4
5
*/
