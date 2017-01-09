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

  void path(int i, int j){
    if (i != j) path(i, p[i][j]);
    u.push_back(j);
  }

  int query(int a, int b){
    return m[a][b];
  }

  vi printpath(int a, int b){
    u.clear();
    path(a, b);
    return u;
  }

  void transitive_closure(){
    //La matriz se llena con 0 en vez de INF:
    //si u -> v entonces m[u][v] = 1 -> costo
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          m[i][j] |= (m[i][k] & m[k][j]);
    //si u esta directamente conectado con v
    //entonces query(u, v) = 1
  }
  //Problema del Minimax:
  //Camino mínimo entre u y v, se busca la 
  //arista más pesada de ese camino mínimo
  void Minimax(){
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          m[i][j] = min(m[i][j], max(m[i][k], m[k][j]));

  }
  bool cycle(){
    //La diagonal de la matriz m se llena con INF y no con cero
    //Se corre Floyd-Warshall normalmente
    for (int i = 0; i < n; i++)
      if (m[i][i] < INF)
        return true;
    return false;
  }
  bool negative_cycle(){
    //La diagonal de la matriz m se llena con INF y no con cero
    //Se corre Floyd-Warshall normalmente
    for (int i = 0; i < n; i++)
      if (m[i][i] < 0)
        return true;
    return false;
  }
  int cheapest_cycle(){
    //La diagonal de la matriz m se llena con INF y no con cero
    //Se corre Floyd-Warshall normalmente
    int min_cost = 0;
    for (int i = 0; i < n; i++)
      if (m[i][i] >= 0)
        min_cost = min(min_cost, m[i][i]);
    return min_cost;
  }
  //Componentes fuertemente conexas con transitive closure
  map<int, vi> SCC(){
    int cont = 0;
    transitive_closure();
    vector<bool> vis(n);
    map<int, vi> ans;
    for (int i = 0; i < n; i++){
      if (vis[i]) continue;
      ans[cont++].push_back(i);
      vis[i] = true;
      for (int j = 0; j < n; j++){
        if (i == j || vis[j]) continue;
        if (m[i][j] && m[j][i])
          ans[cont - 1].push_back(j), vis[j] = true;
      }
    }
    return ans;
  }
};

int main(){
  return 0;
}
/*

*/
