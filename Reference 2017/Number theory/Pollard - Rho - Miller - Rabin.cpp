#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cstdint>
using namespace std;

typedef __int128 lld;
typedef unsigned long long int ull;

inline lld mod_mul(lld a, lld b, lld mod) {
  /*lld x = 0, y = a % mod;
  while (b > 0) {
    if (b & 1)
      x = (x + y) % mod;
    y = (y * 2) % mod;
    b /= 2;
  }
  return x % mod;*/
  return (a * b) % mod; 
}

lld exp(lld a, lld n, lld m) {
  lld resultado = 1;
  for (; n; n >>= 1) {
    if (n & 1) resultado =
      mod_mul(resultado, a, m);
    a = mod_mul(a, a, m);
  }
  return resultado % m;
}


bool witness(lld a, lld n) {
  lld u = n - 1;
  int t = 0;
  while (u % 2 == 0)
    t++, u >>= 1;
  lld next = exp(a, u, n);
  if (next == 1) return false;
  lld last;
  for (int i = 0; i < t; ++i) {
    last = next;
    next = mod_mul(last, last, n);
    if (next == 1) return last != n - 1;
  }
  return next != 1;
}

bool miller_rabin(lld n) {
  int it = 30;
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 0; i < it; ++i) {
    lld a = rand() % (n - 1) + 1;
    if (witness(a, n)) return false;
  }
  return true;
}

lld absolut(lld a) {
  return (a > 0) ? a : - a;
}

lld pollard_rho(lld n) {
  lld x, y, i = 0, k = 2, d;
  x = y = rand() % n;
  while (1) {
    ++i;
    //x = mod_mul(x, x, n);
    x = (x % n * x % n) % n;
    x += 2;
    if (x >= n) x -= n;
    if (x == y) return 1;
    d = __gcd(absolut(x - y), n);
    if (d != 1) return d;
    if (i == k) {
      y = x;
      k *= 2;
    }
  }
  return 1;
}

vector<lld> f;

void factorize(lld n) {
  if (n == 1) return;
  if (miller_rabin(n))
    f.push_back(n);
  else {
    lld d = 1;
    while (d == 1)
      d = pollard_rho(n);
    factorize(d);
    factorize(n / d);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--) {
    lluk; cin >> k;
    lld n = k;
    factorize(n);
    sort(f.begin(), f.end());
    for (lld i = 0; i < f.size(); i++)
      (i == f.size() - 1) ? cout << (llu)f[i] << '\n' : cout << (llu)f[i] << ' ';
    f.clear();
  }
  return 0;
}
/*
5
2
91
40
18055357277566157
9223372036854775807
*/
