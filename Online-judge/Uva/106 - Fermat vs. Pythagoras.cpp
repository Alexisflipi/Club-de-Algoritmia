#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

bool check(int a, int b) {
  return (a % 2 == 0 && b % 2 == 1) || (a % 2 == 1 && b % 2 == 0);
}

ii count(int n) {
  int tam = sqrt(n);
  int acu = 0;
  int ternas = 0;
  vector<bool> bus(n + 1, 0);
  for (int q = 1; q <= tam; q++) {
    for (int p = q + 1; p <= tam; p += 2) {
      if (__gcd(p, q) == 1 && check(p, q)) {
        int x = 2 * p * q;
        int y = p * p - q * q;
        int z = p * p + q * q;
        if (x <= n && y <= n && z <= n) {
          ternas++;
          int t = 1;
          while (t * z <= n) {
            bus[t * x] = 1;
            bus[t * y] = 1;
            bus[t * z] = 1;
            t++;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
    if (!bus[i + 1]) acu++;
  return ii(ternas, acu);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  while (cin >> n) {
    ii ans = count(n);
    cout << ans.first << " " << ans.second << '\n';
  }
  return 0;
}
