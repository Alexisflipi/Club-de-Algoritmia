#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

const double ERROR = 1e-9;
const double M_2PI = 2 * M_PI;

bool Igual(double a, double b) { 
  return fabs(a - b) < ERROR;
}

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

double Magnitud(const Punto& v) {
  return hypot(v.x, v.y);
}

double Distancia(const Punto& p, const Punto& q) {
  return hypot(p.x - q.x, p.y - q.y);
}

double Dot(const Punto& v, const Punto& w) {
  return v.x * w.x + v.y * w.y;
}

Punto Escalar(const Punto& v, double s) {
  return Punto(v.x * s, v.y * s);
}

Punto Trasladar(const Punto& o, const Punto& p) {
  return Punto(p.x - o.x, p.y - o.y);
}

Punto Opuesto(const Punto& v) {
  return Punto(-v.x, -v.y);
}

struct Linea {
  Punto p, q;
  double a, b, c;

  Linea() : p(), q(), a(), b(), c() {}

  Linea(Long A, Long B, Long C)
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
    if (q < p) swap(p, q);
    a = q.y - p.y;
    b = p.x - q.x;
    if (!a) c = p.y, b = -1;
    else if (!b) c = p.x, a = -1;
    else {
      c = -a*p.x - b*p.y;
    }
  }
  bool operator<(const Linea& cmp) const {
    if (!Igual(a, cmp.a)) return a < cmp.a;
    if (!Igual(b, cmp.b)) return b < cmp.b;
    return Igual(c, cmp.c)? false: c < cmp.c;
  }
};

Punto ProyeccionEnRecta(const Punto& v, const Linea& r) {
  Punto a = Trasladar(r.p, v), b = Trasladar(r.p, r.q);
  return Trasladar(Opuesto(r.p), Escalar(b,
      Dot(a, b) / pow(Magnitud(b), 2)));
}

double DistanciaPuntoRecta(const Punto& p, const Linea& r) {
  return Distancia(ProyeccionEnRecta(p, r), p);
}

double solve(vector<Punto> p) {
  double mini = 1e10;
  int n = p.size();
  for (int i = 0; i < n; i++) {
    Linea s(p[i % n], p[(i + 2) % n]);
    mini = min(mini, DistanciaPuntoRecta(p[(i + 1) % n], s)/2.0);
  }
  return mini;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<Punto> coor;
  for (int i = 0; i < n; i++) {
    double x, y; cin >> x >> y;
    coor.push_back(Punto(x, y));
  }
  cout << fixed << setprecision(6);
  cout << solve(coor) << '\n';
  return 0;
}
