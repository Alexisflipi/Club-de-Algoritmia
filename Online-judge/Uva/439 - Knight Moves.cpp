#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int A = 8;
const int INF = (1 << 30);
int mx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int my[] = {-1, -2, -2, -1, 1, 2, 2, 1};

struct G{
  int n, m;
  vector<vi> matrix;
  vector<vii> p;
  vii path;

  G(int N, int M) : n(N), m(M), 
  matrix(N, vi(M, 0)), p(N, vector<ii>(M, ii())) {}

  //Si es multisource, agregar al principio de Q
  int bfs2D(ii s, ii t) {
    vector<vi> dist(n, vi(m, INF));
    queue<ii> Q;
    Q.push(s); dist[s.fst][s.snd] = 0;
    while (!Q.empty()) {
      ii u = Q.front(); Q.pop();
      for (int i = 0; i < 8; i++) {
        int x = u.fst + mx[i];
        int y = u.snd + my[i];
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (matrix[x][y] == 1) continue;
        if (dist[x][y] == INF) {
          dist[x][y] = dist[u.fst][u.snd] + 1;
          p[x][y] = u;
          if (ii(x, y) == t)
            return dist[x][y];
          Q.push(ii(x, y));
        }
      }
    }
    return dist[t.fst][t.snd];
  }
};

map<char, int> mapeo;
void m() {
  for (int i = 0; i < 8; i++)
    mapeo[char(i  + 'a')] = i;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  m();
  string s, t;
  while (cin >> s >> t) {
    ii source = ii(mapeo[s[0]], (s[1] - '0') - 1);
    ii sink =   ii(mapeo[t[0]], (t[1] - '0') - 1);
    G graph(A, A);
    int res = graph.bfs2D(source, sink);
    cout << "To get from " << s << " to " << t << " takes " << res << " knight moves.\n";
  }
  return 0;
}
/*
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6
*/
