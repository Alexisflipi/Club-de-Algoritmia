#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

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

int main() {
  return 0;
}
