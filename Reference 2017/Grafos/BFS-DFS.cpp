#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

const int INF = (1 << 30);
int mx[] = {-1, 0, 1, 0};
int my[] = {0, -1, 0, 1};

struct G{
  int n;
  int m;
  vector<vi> ady;
  vector<vi> matrix;
  vi visit;
  G(int N, int M) : n(N), ady(N), visit(N), m(M), matrix(N, vi(M, 0)) {}

  void connect(int a, int b) {
    ady[a].push_back(b);
    ady[b].push_back(a);
    //matrix[a][b] = 1 solo  bfs2D o matrix de adyacencia
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
  
  int bfs2D(ii s, ii t) {
    vector<vi> dist(n, vi(m, INF));
    queue<ii> Q;
    Q.push(s); dist[s.fst][s.snd] = 0;
    while (!Q.empty()) {
      ii u = Q.front(); Q.pop();
      for (int i = 0; i < 4; i++) {
        int x = u.fst + mx[i];
        int y = u.snd + my[i];
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (matrix[x][y] == 1) continue;
        if (dist[x][y] == INF) {
          dist[x][y] = dist[u.fst][u.snd] + 1;
          Q.push(ii(x, y));
        }
      }
    }
    return dist[t.fst][t.snd];
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
  G graph(V, 0);
  for (int i = 0; i < V; i++)
    if (!graph.visit[i])
      graph.dfs(i);
  return 0;
}
