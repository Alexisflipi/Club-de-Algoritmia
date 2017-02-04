#include <bits/stdc++.h>
using namespace std;

//Esta funcion permite retornar
//El número máximo de caballos que
//pueden ser colocados en un tablero
//de ajedrez de tamaño n x m sin que
//choquen con sus movimientos

int solve_knight(int n, int m){
  if(n > m) swap(n,m);
  if(n == 1) return m;
  if(n == 2) return m / 4 * 4 + (m % 4 == 1? 2 : (m % 4 >= 2? 4 : 0));
  return (n*m + 1) / 2;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    if (!n && !m) break;
    int ans = solve_knight(n, m);
    cout << ans << " knights may be placed on a " << n << " row " << m << " column board.\n";
  }
  return 0;
}
/*
2 3
5 5
4 7
0 0
*/
