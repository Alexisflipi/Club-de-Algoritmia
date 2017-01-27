#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = (1 << 30);
int mx[] = {-1, 0, 1, 0};
int my[] = {0, -1, 0, 1};

struct G{
  int n, m;
  vector<vi> matrix;
  vector<vii> p;
  vii path;

  G(int N, int M) : n(N), m(M), 
  matrix(N, vi(M, 0)), p(N, vector<ii>(M, ii())) {}

  void connect(int a, int b) {
    //se modifica de acuerdo al grid 2D
    matrix[a][b] = 1;
  }
  //Imprime el camino de cualquier 
  //nodo v al nodo s -> printPath(v, s)
  void print(ii u, ii s) {
    if (u == s) { path.push_back(s); return; }
    printPath(p[u.fst][u.snd], s);
    path.push_back(u);
  }
  
  vii printPath(ii u, ii s) {
    path.clear();
    print(u, s);
    return path;
  }
  //Si es multisource, agrgar al principio de Q
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
          p[x][y] = u;
          Q.push(ii(x, y));
        }
      }
    }
    return dist[t.fst][t.snd];
  }
};

int main() {
  return 0;
}
