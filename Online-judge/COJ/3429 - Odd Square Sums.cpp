#include <bits/stdc++.h>
using namespace std;

//Suma de cuadrados pares  : 2 * p * (p + 1) * (2 * p + 1) / 3
//suma de cuadrados impares: (p + 1) * (2 * p + 1) * (2 * p + 3) / 3

typedef long long lld;
const lld MOD = 1e9 + 7;

lld power(lld a, lld n) {
  lld ret = 1;
  while (n > 0) {
    if (n % 2 == 1) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    n /= 2;
  }
  return ret % MOD;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  lld N;
  while (cin >> N) {
    lld p = (N - 1)/2;
    lld a = (p + 1) * (2 * p + 1) * (2 * p + 3) % MOD;
    lld b = power(3, MOD - 2);
    cout << (a * b) % MOD << "\n";
  }
  return 0;
}
