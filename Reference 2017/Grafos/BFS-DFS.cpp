#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

const int INF = (1 << 30);

struct G{
  int n;
  vector<vi> ady;
  vi visit;
  G(int N) : n(N), ady(N), visit(N) {}

  void connect(int a, int b) {
    ady[a].push_back(b);
    ady[b].push_back(a);
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

  void dfs(int u) {
    visit[u] = 1;
    for (auto &v : ady[u])
      if (!visit[v])
        dfs(v);
  }
};

int main() {
  int V;
  G graph(V);
  for (int i = 0; i < V; i++)
    if (!graph.visit[i])
      graph.dfs(i);
  return 0;
}
