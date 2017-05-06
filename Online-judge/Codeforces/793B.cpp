#include <bits/stdc++.h>
#define fst first
#define snd second
#define forn(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;

typedef pair<int, int> ii;

const int INF = (1 << 30);
const int MAX = 1005;

int n, m;
int matrixh[MAX][MAX];
int matrixv[MAX][MAX];
int  matrix[MAX][MAX];

int query(ii a, ii b, int d) {
  if (d)
    return matrixh[b.fst][b.snd] - matrixh[a.fst][a.snd - 1];
  return matrixv[b.fst][b.snd] - matrixv[a.fst - 1][a.snd];
}

bool check(ii r1, ii r2) {
  forn (i, 1, m + 1) {
    ii aux = ii(r1.fst, i);
    ii tem = ii(r2.fst, i);
    int flag = 1;
    if (i >= 1 && i < r2.snd) {
      flag &= !query(aux, r1, 1);
      flag &= !query(tem, r2, 1);
      flag &= !query(aux, tem, 0);
    } else {
      if (i >= r1.snd && i <= r2.snd + 1) {
        flag &= !query(r1, aux, 1);
        flag &= !query(tem, r2, 1);
        flag &= !query(aux, tem, 0);    
      } else {
        flag &= !query(r1, aux, 1);
        flag &= !query(r2, tem, 1);
        flag &= !query(aux, tem, 0);
      }
    }
    if (flag) return 1;
  }
  forn(i, r1.fst, r2.fst + 1) {
    ii aux = ii(i, r1.snd);
    ii tem = ii(i, r2.snd);
    int flag = 1;
    flag &= !query(r1, aux, 0);
    flag &= !query(tem, r2, 0);
    flag &= !query(aux, tem, 1);
    if (flag) return 1;
  }
  return 0;
}

void pre(int n, int m) {
  forn(i, 1, n + 1)
    forn(j, 1, m + 1)
      matrixh[i][j] += matrixh[i][j - 1],
      matrixv[i][j] += matrixv[i - 1][j];
}
int main() {
  cin >> n >> m;
  ii s, t;
  forn(i, 1, n + 1) {
    forn(j, 1, m + 1) {
      char c; cin >> c;
      if (c == 'S') s = ii(i, j), matrix[j][i] = 2;
      if (c == 'T') t = ii(i, j), matrix[j][i] = 3;
      if (c == '*') matrixv[i][j] = 1, matrixh[i][j] = 1, matrix[j][i] = 1;
    }
    cin.ignore();
  }
  pre(n, m);
  
  ii r1 = min(s, t);
  ii r2 = max(s, t);
  bool u = check(r1, r2);

  swap(n, m);
  memset(matrixh, 0, sizeof matrixh);
  memset(matrixv, 0, sizeof matrixv);
  forn(i, 1, n + 1)
    for (int j = m; j > 0; j--) {
      if (matrix[i][j] == 2) matrix[i][j] = 0, s = ii(i, m - j + 1);
      if (matrix[i][j] == 3) matrix[i][j] = 0, t = ii(i, m - j + 1);
      matrixv[i][m - j + 1] = matrixh[i][m - j + 1] = ((matrix[i][j] == 1) ? 1 : 0);
    }
  r1 = min(s, t);
  r2 = max(s, t);
  pre(n, m);
  bool v = check(r1, r2);
  if (u || v)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
/*
5 6
......
.*T*.*
..**S.
*.**..
......

6 5
.*...
...*.
.**T.
.***.
..S..
...*.
*/
