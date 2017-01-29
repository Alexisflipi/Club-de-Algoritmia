#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> ii;
typedef vector<char> vi;

int mx[] = {-1, 0, 1, 0};
int my[] = {0, -1, 0, 1};
string s;

struct G{
  int n, m;
  int stickers;
  vector<vi> matrix;
  G(int N, int M) : n(N), m(M), matrix(N, vi(M)), stickers(0) {}
  void connected(int a, int b, char c) {
    matrix[a][b] = c;
  }

  void dfs(int i, int j, int idx, int dir) {
    if (matrix[i][j] == '*') stickers++, matrix[i][j] = '.';
    if (idx == s.size()) return;
    if (s[idx] == 'D')
      dfs(i, j, idx + 1, (dir - 1 + 4) % 4);
    if (s[idx] == 'E')
      dfs(i, j, idx + 1, (dir + 1 + 4) % 4);
    if (s[idx] == 'F') {
      int x = i + mx[dir];
      int y = j + my[dir];
      if (x < 0 || x >= n || y < 0 || y >= m)
        dfs(i, j, idx + 1, dir);
      else
        if (matrix[x][y] == '#')
          dfs(i, j, idx + 1, dir);  
        else
          dfs(x, y, idx + 1, dir);
    }
  }
  int solve(ii t, int dir) {
    dfs(t.fst, t.snd, 0, dir);
    return stickers;
  }
};

int bus(char c) {
  if (c == 'N') return 1;
  if (c == 'O') return 2;
  if (c == 'S') return 3;
  if (c == 'L') return 4;
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, t;
  char c;
  while (cin >> n >> m >> t) {
    if (n == 0 && m == 0 && t == 0) break;
    G graph(n, m);
    int d;
    ii r;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        cin >> c, graph.connected(i, j, c);
        if (bus(c))
          d = bus(c), r = ii(i, j);
      }
    cin >> s;
    cout << graph.solve(r, --d) << "\n";
  }
}
/*
3 3 2
***
*N*
***
DE
4 4 5
...#
*#O.
*.*.
*.#.
FFEFF
10 10 20
....*.....
.......*..
.....*....
..*.#.....
...#N.*..*
...*......
..........
..........
..........
..........
FDFFFFFFEEFFFFFFEFDF
0 0 0
*/
