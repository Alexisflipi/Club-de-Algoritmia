#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const int INF = (1 << 25);
const int A = 21;

struct G{
  int n;
  vector<vi> m;
  vector<vi > p;
  vi u;
  //Si es transitive closure, cambiar INF por 0 en la matriz m
  G(int N) : n(N), m(N, vi(N, INF)), p(N, vector<int>(N, 0)) {}

  void conect(int a, int b, int costo){
    m[a][b] = costo;
  }

  void Floyd_Warshall(){
    for (int k = 0; k < n; k++)
      m[k][k] = 0; //si no es multigrafo

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        p[i][j] = i; // arreglo de padres

    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if (m[i][k] + m[k][j] < m[i][j]){
            m[i][j] = m[i][k] + m[k][j];
            p[i][j] = p[k][j];
          }
  }
  int query(int x, int y){
    return m[x][y];
  }
};
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int r;
  int t = 0;
  while (cin >> r){
    G grafo(A);
    for (int i = 0; i < r; i++){
      int num; cin >> num;
      grafo.conect(1, num, 1);
      grafo.conect(num, 1, 1);
    }
    for (int i = 2; i < 20; i++){
      cin >> r;
      for (int j = 0; j < r; j++){
        int num; cin >> num;
        grafo.conect(i, num, 1);
        grafo.conect(num, i, 1);
      }
    }
    grafo.Floyd_Warshall();
    cout << "Test Set #" << ++t << "\n";
    int N; cin >> N;
    for (int i = 0; i < N; i++){
      stringstream ss1;
      stringstream ss2;
      int a, b; cin >> a >> b;
      int costo = grafo.query(a, b);
      string r1, r2;
      ss1 << a; ss1 >> r1;
      ss2 << b; ss2 >> r2;
      if (r1.size() == 1)
        r1 = " " + r1;
      if (r2.size() == 1)
        r2 = " " + r2;
      cout << r1 << " to " << r2 << ": " << costo << "\n";
    }
    cout << "\n";
  }
}
/*
1 3
2 3 4
3 4 5 6
1 6
1 7
2 12 13
1 8
2 9 10
1 11
1 11
2 12 17
1 14
2 14 15
2 15 16
1 16
1 19
2 18 19
1 20
1 20
5
1 20
2 9
19 5
18 19
16 20
4 2 3 5 6
1 4
3 4 10 5
5 10 11 12 19 18
2 6 7
2 7 8
2 9 10
1 9
1 10
2 11 14
3 12 13 14
3 18 17 13
4 14 15 16 17
0
0
0
2 18 20
1 19
1 20
6
1 20
8 20
15 16
11 4
7 13
2 16
*/
