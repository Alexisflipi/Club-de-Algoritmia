#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const int INF (1<<25);

//Algoritmo Floyd-Warshall

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
  int T; cin >> T;
  for (int t = 0; t < T; t++){
    int n, m; cin >> n >> m;
    G graph(n);
    for (int i = 0; i < m; i++){
      int a, b; cin >> a >> b;
      graph.conect(a, b, 1);
      graph.conect(b, a, 1);
    }
    int s, d; cin >> s >> d;
    graph.Floyd_Warshall();
    int maxi = -INF;
    for (int k = 0; k < n; k++)
      maxi = max(maxi, graph.query(s, k) + graph.query(k, d));
    cout << "Case " << t + 1 << ": " << maxi << "\n";
  }
  return 0;
}
/*
2
4
3
0 1
2 1
1 3
0 3
2
1
0 1
1 0
*/
