#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

const double ERROR = 1e-9;
const double M_2PI = 2 * M_PI;

// Tolerancia en flotantes.
bool Igual(double a, double b) { 
  return fabs(a - b) < ERROR;
}

// Punto en 2D.
struct Punto {
  double x, y;

  Punto() : x(), y() {}
  Punto(double X, double Y) : x(X), y(Y) {}

  // Izquierda a derecha, abajo a arriba.
  bool operator<(const Punto& cmp) const {
    if (!Igual(x, cmp.x)) return x < cmp.x;
    return Igual(y, cmp.y)? false: y < cmp.y;
  }

  bool operator==(const Punto& cmp) const {
    return Igual(x, cmp.x) && Igual(y, cmp.y);
  } 
};

struct Linea {
  Punto p, q;
  lld a, b, c; // <comment/>
  //double a, b, c; // <uncomment/>

  Linea() : p(), q(), a(), b(), c() {}

  Linea(lld A, lld B, lld C)
    : p(), q(), a(A), b(B), c(C) {
    if (Igual(a, 0)) {
      c /= -b; b = -1;
      p = Punto(0, c);
      q = Punto(1, c);
    } else if (Igual(b, 0)) {
      c /= -a; a = -1;
      p = Punto(c, 0);
      q = Punto(c, 1);
    } else {
      p = Punto(-c/a, 0);
      q = Punto(-(b+c)/a, 1);
    } if (q < p) swap(p, q);
  }

  Linea(const Punto& P, const Punto& Q)
    : p(P), q(Q), a(), b(), c() {
    // Asegura p como punto menor.
    if (q < p) swap(p, q);
    a = q.y - p.y;
    b = p.x - q.x;
    if (!a) c = p.y, b = -1;
    else if (!b) c = p.x, a = -1;
    else {
      // <comment>
      c = abs(__gcd(a, b));
      a /= c, b /= c;
      // </comment>
      c = -a*p.x - b*p.y;
    }
  }

  // ¡PELIGRO! Ordena por ecuacion de recta.
  bool operator<(const Linea& cmp) const {
    if (!Igual(a, cmp.a)) return a < cmp.a;
    if (!Igual(b, cmp.b)) return b < cmp.b;
    return Igual(c, cmp.c)? false: c < cmp.c;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  lld N;
  while (cin >> N and N) {
    vector<Punto> coor;
    for (lld i = 0; i < N; i++) {
      lld x, y; cin >> x >> y;
      coor.push_back(Punto(x, y));
    }
    set<Linea> bus;
    for (lld i = 0; i < N; i++)
      for (lld j = i + 1; j < N; j++)
        bus.insert(Linea(coor[i], coor[j]));
    cout << bus.size() << "\n";
  }
  return 0;
}
/*
6
1 1
2 2
3 3
4 4
5 5
6 6
5
3 2
4 1
4 2
1 2
2 3
0
*/
