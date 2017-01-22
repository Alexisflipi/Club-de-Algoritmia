#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const int INF (1<<25);
const int A = 105;
struct G{
  int n;
  vector<vi> m;
  G(int N) : n(N), m(N, vi(N, INF)) {}

  void conect(int a, int b, int costo){
    m[a][b] = costo;
  }

  void Floyd_W(){
    for (int k = 0; k < n; k++)
      m[k][k] = 0; //si no es multigrafo
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
  }

  int query(int a, int b){
    return m[a][b];
  }

  double solve(){
    int cont = 0, acu = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (query(i, j) != INF && query(i, j) != 0)
          cont++, acu += query(i, j);
    return (double)acu/cont;
  }
};

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b;
  int t = 0;
  while (cin >> a >> b and a and b){
    G graph(A);
    graph.conect(a - 1, b - 1, 1);
    while (cin >> a >> b and a and b)
      graph.conect(a - 1, b - 1, 1);
    
    graph.Floyd_W();
    cout << fixed << setprecision(3);
    double r = graph.solve();
    cout << "Case " << ++t << ": average length between pages = " << r << " clicks\n";
  }
  return 0;
}
/*
1 2   2 4   1 3   3 1   4 3   0 0
1 2   1 4   4 2   2 7   7 1   0 0
0 0
*/
