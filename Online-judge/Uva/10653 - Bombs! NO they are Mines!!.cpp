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
  int n, m;
  vector<vi> matrix;

  G(int N, int M) : n(N), m(M), matrix(N, vi(M, 0)) {}

  void connect(int a, int b) {
    matrix[a][b] = 1;
  }

  int bfs(ii s, ii t) {
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

};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int r, c;
  while (cin >> r >> c and r and c) {
    G graph(r, c);
    int bombs; cin >> bombs;
    for (int i = 0; i < bombs; i++) {
      int r, n, a; cin >> r >> n;
      for (int j = 0; j < n; j++)
        cin >> a, graph.connect(r, a);
    }
    int f, g;
    cin >> f >> g; ii s(f, g);
    cin >> f >> g; ii t(f, g);
    cout << graph.bfs(s, t) << "\n";
  }
  return 0;
}
/*
10 10
9
0 1 2
1 1 2
2 2 2 9
3 2 1 7
5 3 3 6 9
6 4 0 1 2 7
7 3 0 3 8
8 2 7 9
9 3 2 3 4
0 0
9 9
0 0
*/
