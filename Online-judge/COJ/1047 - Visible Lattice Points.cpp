#include <bits/stdc++.h>
using namespace std;

const int A = 105;
int f[A];

int calc(int n) {
  int cont = 0;
  for (int y = 0; y < n; y++)
    for (int z = 0; z < n; z++)
      if (__gcd(y, __gcd(z, n)) == 1)
        cont += 3;
  for (int z = 0; z < n; z++)
    if (__gcd(n, z) == 1)
      cont += 3;
  if (__gcd(n, n) == 1)
    cont++;
  return cont;
}

void pre() {
  f[0] = 0;
  for (int i = 1; i < A; i++)
    f[i] = f[i - 1] + calc(i);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  pre();
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    cout << f[N] << "\n";
  }
  return 0;
}
/*
3
1
2
5
*/
