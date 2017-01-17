#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

struct Punto{
  lld x, y, z;
  Punto(lld a, lld b, lld c) : x(a), y(b), z(c) {}
};

lld ad(Punto &A, Punto &B) {
  lld x = (B.x - A.x);
  lld y = (B.y - A.y);
  lld z = (B.z - A.z);
  return abs(__gcd(x, abs(__gcd(y, z)))) - 1;
}

lld solve(Punto &A, Punto &B) {
  lld r = ad(A, B);
  return r + 2;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  lld a, b, c;
  while (cin >> a >> b >> c) {
    Punto A = Punto(a, b, c);
    cin >> a >> b >> c;
    Punto B = Punto(a, b, c);
    cout << solve(A, B) << "\n";
  }
  return 0;
}
