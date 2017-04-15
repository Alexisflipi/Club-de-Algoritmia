#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

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

//Obtiene la distancia mínima con coordenadas 
//de movimientos de una knight a otro
//Ojo, el tablero no esta delimitado
lld knight_distance(lld x1, lld y1, lld x2, lld y2) {
  lld x = abs(x2 - x1), y = abs(y2 - y1);    
  if (x > y) swap(x, y);
  assert(x <= y);
  if (x == 0 and y == 1) return 3;
  if (x == 2 and y == 2) return 4;
  lld d = max((y + 1) / 2, (x + y + 2) / 3);
  if (d % 2 != (x + y) % 2) d++;
  return d;
}
//Bitmask: Da todas las posibles configuraciones
//Complejidad: 2^n
int bitmask(int tam) {
  //tam es el tamaño de la máscara de bits
  for (int i = 0; i < (1<<tam) - 1; i++)
    for (int j = 0; j < tam; j++)
      if (i & (1<<j))
        //El j ésimo bit esta prendido
}
//p = (N - 1)/2 -> suma de cuadrados de 1 a N:
//Suma de cuadrados pares  : 2 * p * (p + 1) * (2 * p + 1) / 3
//suma de cuadrados impares: (p + 1) * (2 * p + 1) * (2 * p + 3) / 3

//modulo de negativos
lli mod(lli a, lli b) {
	return (a >= 0) ? a % b : (b - abs(a % b)) % b;
}
int main() {
  return 0;
}
