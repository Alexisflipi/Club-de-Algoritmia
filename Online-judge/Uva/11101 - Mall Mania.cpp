#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = (1 << 30);
const int A = 2005;
int mx[] = {-1, 0, 1, 0};
int my[] = {0, -1, 0, 1};

set<ii> mall1;
set<ii> mall2;

struct G{
  int n;
  G(int N) : n(N) {}

  int bfs2D(set<ii> m) {
    vector<vi> dist(A, vi(A, INF));
    queue<ii> Q;
    for (auto &mall : m)
      Q.push(mall), dist[mall.fst][mall.snd] = 0;
    while (!Q.empty()) {
      ii u = Q.front(); Q.pop();
      for (int i = 0; i < 4; i++) {
        int x = u.fst + mx[i];
        int y = u.snd + my[i];
        if (x < 0 || y < 0 || x >= A || y >= A) continue;
        if (dist[x][y] == INF) {
          dist[x][y] = dist[u.fst][u.snd] + 1;
          if (mall2.find(ii(x, y)) != mall2.end())
            return dist[x][y];
          Q.push(ii(x, y));
        }
      }
    }
    return 0;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, x, y;
  while (cin >> n && n) {
    G graph(n);
    for (int i = 0; i < n; i++)
      cin >> x >> y, mall1.insert(ii(x, y));
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> x >> y, mall2.insert(ii(x, y));
    cout << graph.bfs2D(mall1) << '\n';
    mall1.clear();
    mall2.clear();
  }
  return 0;
}
/*
4
0 0 0 1 1 1 1 0
6
4 3 4 2 3 2
2 2 2 3
3 3
0
*/
