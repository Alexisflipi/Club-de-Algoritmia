#include <bits/stdc++.h>
using namespace std;

// Fuente: club de algoritmia ESCOM
// Autor: Ethan Jiménez
typedef long long lld;
const lld INF = (1 << 30);

// Segment Tree version dinamica. Para generar el
// arbol completo deben llamar a la funcion Construir.
// CUIDADO: Para usarlo deben especificar el tipo de
// dato a utilizar; SegTree<lld> por ejemplo.

template<class T>
struct SegTree {
  T dato; lld i, d;
  SegTree* izq, *der;

  SegTree(lld I, lld D) : izq(NULL), der(NULL), i(I), d(D), dato() {}
  
  ~SegTree() {
    if (izq) delete izq;
    if (der) delete der;
  }
  
  T Construir() {
    if (i == d) return dato = T();
    lld m = (i + d) >> 1;
    izq = new SegTree(i, m);
    der = new SegTree(m + 1, d);
    return dato = izq->Construir() + der->Construir();
  }
  
  T Actualizar(lld a, T v) {
    if (a < i || d < a) return dato;
    if (a == i && d == a) return dato = v;
    if (!izq) {
      lld m = (i + d) >> 1;
      izq = new SegTree(i, m);
      der = new SegTree(m + 1, d);
    }
    return dato = izq->Actualizar(a, v) + der->Actualizar(a, v);
  }
  
  T Query(lld a, lld b) {
    if (b < i || d < a) return T();
    if (a <= i && d <= b) return dato;
    return izq? izq->Query(a, b) + der->Query(a, b): T();
  }
};

// A continuación se ejemplifica como sobrecargar
// el operador + dentro de una estructura para poder
// reutilizar el codigo del Segment Tree facilmente.
// El ejemplo sobrecarga el + por la funcion de maximo.
// Es MUY IMPORTANTE tener un constructor por defecto.

struct MaxInt {
  lld d; MaxInt(lld D) : d(D) {}
  MaxInt() : d(1) {} // IMPORTANTE!
  MaxInt operator+(const MaxInt& o) {
    return MaxInt(d * o.d);
  }
};

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lld n, k;
  while (cin >> n >> k) {
    SegTree<MaxInt> sg(0, n);
    string s = "";
    for (lld i = 0; i < n; i++) {
      lld a; cin >> a;
      if (a != 0) (a > 0) ? a = 1 : a = -1;
      sg.Actualizar(i, MaxInt(a));
    }
    for (lld i = 0; i < k; i++) {
      char c; cin >> c;
      if (c == 'C') {
        lld idx, a; cin >> idx >> a;
        if (a != 0) (a > 0) ? a = 1 : a = -1;
        sg.Actualizar(--idx, MaxInt(a));
      }else {
        lld x, y; cin >> x >> y;
        lld d = sg.Query(--x, --y).d;
        if (d < 0)  s += '-';
        if (d > 0)  s += '+';
        if (d == 0) s += '0';
      }
    }
    cout << s << "\n";
  }
  return 0;
}
