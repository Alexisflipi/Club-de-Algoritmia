#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, pair<int, int>> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int A = 6;

const int INF = (1 << 30);
int mx[] = {-1, 0, 1, 0};
int my[] = {0, -1, 0, 1};
viii v;
viii h;
vector<vii> dir;

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
    print(p[u.fst][u.snd], s);
    path.push_back(u);
  }
  
  vii printPath(ii u, ii s) {
    path.clear();
    print(u, s);
    return path;
  }
  
  bool f(viii t, int x, int y, bool flag) {
    for (auto &r : t) {
      int c = r.fst;
      int a = r.snd.fst;
      int b = r.snd.snd;
      if (x == c && !flag)
        if ((y <= b && y >= a) && (y + 1 <= b && y + 1 >= a))
          return 0;
      if (x + 1 == c && flag)
        if ((y <= b && y >= a) && (y + 1 <= b && y + 1 >= a))
          return 0;
    }
    return 1;
  }

  bool check(int flag, int x, int y) {
    if (flag % 2 == 0)
      return f(h, x, y, flag/2);
    return f(v, y, x, flag/2);
  }

  void bfs2D(ii s, ii t) {
    vector<vi> dist(n, vi(m, INF));
    queue<ii> Q;
    Q.push(s); dist[s.fst][s.snd] = 0;
    while (!Q.empty()) {
      ii u = Q.front(); Q.pop();
      for (int i = 0; i < 4; i++) {
        int x = u.fst + mx[i];
        int y = u.snd + my[i];
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (!check(i, u.fst, u.snd)) continue;
        if (dist[x][y] == INF) {
          dist[x][y] = dist[u.fst][u.snd] + 1;
          p[x][y] = u;
          dir[x][y] = ii(mx[i], my[i]);
          Q.push(ii(x, y));
        }
      }
    }
  }
};
map<ii, char> bus;

void mapeo() {
  bus[ii(-1, 0)] = 'N';
  bus[ii(0, -1)] = 'W';
  bus[ii(1, 0)] = 'S';
  bus[ii(0, 1)] = 'E';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int x, y;
  mapeo();
  while (cin >> x >> y && x && y) {
    G graph(A, A);
    dir = vector<vii>(A, vector<ii>(A, ii()));
    v.clear();
    h.clear();
    ii s = ii(--y, --x);
    cin >> x >> y;
    ii t = ii(--y, --x);
    for (int i = 0; i < 3; i++) {
      int a, b, c, d;
      cin >> b >> a >> d >> c;
      if (b == d && a == c) continue;
      if (b == d) v.push_back(make_pair(b, ii(a, c)));
      else h.push_back(make_pair(a, ii(b, d)));
    }
    graph.bfs2D(s, t);
    vii ans = graph.printPath(t, s);
    string r = "";
    for (auto &it : ans) {
      ii g = dir[it.fst][it.snd];
      if (it == s) continue;
      r = r + bus[g];
    }
    cout << r << "\n";
  }
  return 0;
}
/*
1 6
2 6
0 0 1 0
1 5 1 6
1 5 3 5
1 6
2 6
0 0 1 0
1 5 1 5
1 5 3 5
0 0
*/
