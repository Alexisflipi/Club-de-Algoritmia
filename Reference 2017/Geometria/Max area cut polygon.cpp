#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef long long lld;
typedef pair<lld, lld> ii;
typedef vector<ii> vii;
typedef vector<lld> vi;

//Dado un poligono de n vertices encontrar una pareja
//de vertices tal que la diferencia de las
//areas del poligono al cortarlo sea minima
//Time complexity: O(n log n)

struct P{
  lld n;
  lld area;
  vi ac;
  vii coor;
  P(lld N) : n(N), ac(2 * N), coor(N) {}
  //Agrega un punto al polígono
  void add(lld idx, ii p) {
    coor[idx] = p;
  }
  //Obtiene area del paralelogramo entre dos puntos
  lld productCruz(ii a, ii b) {
    return (a.fst * b.snd - b.fst * a.snd);
  }
  //calcula el area total del poligono
  void getArea() {
    area = 0;
    for (lld i = 0; i < n; i++)
      area += productCruz(coor[i % n], coor[(i + 1) % n]);
  }
  //Precalcula todas las areas para formar la funcion f
  void precalculate() {
    for(lld i = 0; i < 2 * n; i++){
      ac[i] = productCruz(coor[i % n], coor[(i + 1) % n]);
      if(i > 0) ac[i] += ac[i - 1];
    }
  }
  //Calcula el area maxima al cortar el poligono en 
  //dos partes usando sus vértices: O(1)
  lld f(lld a, lld b){
    lld dev = ac[b - 1];
    if(a > 0) dev -= ac[a - 1];
    lld A1 = abs(dev + productCruz(coor[b % n], coor[a % n]));
    lld A2 = area - A1;
    return max(A1, A2);
  }
  //Encuentra el conjunto de puntos muy cercanos al maximo en O(log n)
  ii TernarySearch(lld lo) {
    lld i = lo;
    lld hi = n + i - 1;
    for (lld j = 0; j < 35; j++) {
      lld m1  = (2 * lo + hi)/3;
      lld m2 = (lo + 2 * hi)/3;
      (f(i, m1) < f(i, m2)) ? hi = m2 : lo = m1;
    }
    return ii(lo, hi);
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  lld n;
  lld x, y; 
  cin >> n;
  P *polygon = new P(n);

  for (lld i = 0; i < n; i++) {
    cin >> x >> y;
    polygon -> add(i, ii(x, y));
  }
  polygon -> getArea();
  polygon -> precalculate();
  lld area_total = polygon -> area;
  lld mini = (1LL<<60LL);
  ii ans;
  for (lld i = 0; i < n; i++) {
    //Estas en el i-esimo punto del poligono
    ii t = polygon -> TernarySearch(i);
    //Encuentra una cota confiable donde estara el maximo
    for (lld j = t.fst; j < t.snd; j++) {
      lld A1 = polygon -> f(i, j);
      lld A2 = area_total - A1;
      if (abs(A1 - A2) < mini) {
        mini = abs(A1 - A2);
        ans = ii(i + 1, j + 1);
      }
    }
  }
  cout << ans.fst << " " << ans.snd << '\n';
  return 0;
}
/*
4
0 0
1 0
1 1
0 1

5
0           1
0           0
2           -1
2           1
1           2
*/         
