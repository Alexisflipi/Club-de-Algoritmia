#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<string, string> ii;
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

  int query(int a, int b){
    return m[a][b];
  }

  int solve(){
    int maxi = -INF;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (query(i, j) == INF) return INF;
        else maxi = max(maxi, query(i, j));
    return maxi;
  }
};
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int V, E;
  int t = 0;
  while (cin >> V >> E and V and E){
    G graph(V);
    vector<ii> Edgelist;
    set<string> bus;
    map<string, int> m;
    int node = 0;
    for (int i = 0;  i < E; i++){
      string a, b; cin >> a >> b;
      bus.insert(a);
      bus.insert(b);
      Edgelist.push_back(ii(a, b));
    }
    for (auto it : bus)
      m[it] = node++;
    for (auto e : Edgelist){
      graph.conect(m[e.first], m[e.second], 1);
      graph.conect(m[e.second], m[e.first], 1);
    }
    graph.Floyd_Warshall();
    int r = graph.solve();
    if (r != INF)
      cout << "Network " << ++t << ": " << r << "\n";
    else
      cout << "Network " << ++t << ": DISCONNECTED\n";
    cout << "\n";
  }
  return 0;
}
/*
4  4
Ashok  Kiyoshi   Ursala  Chun   Ursala  Kiyoshi
Kiyoshi  Chun
4  2
Ashok  Chun   Ursala  Kiyoshi
6 5
Bubba  Cooter   Ashok  Kiyoshi   Ursala  Chun
Ursala  Kiyoshi   Kiyoshi  Chun
0  0
*/
