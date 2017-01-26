#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;

const int INF = (1 << 30);
int mx[] = {-1, 0, 1, 0};
int my[] = {0, -1, 0, 1};

struct G{
  int n, m;
  vector<vi> matrix;
  G(int N, int M) : n(N), m(M), matrix(N, vi(M, 0)) {}

  void connect(int a, int b, int costo) {
    matrix[a][b] = costo;
  }

  vector<vi> Dijsktra2D(ii s, ii t) {
    vector<vi> dist(n, vi(m, INF));
    priority_queue<iii, vector<iii>, greater<iii>> Q;
    dist[s.fst][s.snd] = matrix[s.fst][s.snd];
    Q.push(make_pair(matrix[s.fst][s.snd], s));
    while (!Q.empty()) {
      auto v = Q.top(); Q.pop();
      int costo = v.fst;
      int p = v.snd.fst;
      int q = v.snd.snd;
      if (dist[p][q] < costo) continue;
      for (int i = 0; i < 4; i++) {
        int x = p + mx[i];
        int y = q + my[i];
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (dist[p][q] + matrix[x][y] < dist[x][y]) {
          dist[x][y] = dist[p][q] + matrix[x][y]; 
          Q.push(make_pair(dist[x][y], ii(x, y)));
        }
      }
    }
    return dist;
  }
};

int main() {
  return 0;
}
