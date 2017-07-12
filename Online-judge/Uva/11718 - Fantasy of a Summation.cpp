#include <bits/stdc++.h>
#define forn(i, a, b) for (int i = a; i < b; i++)
using namespace std;

typedef long long lli;

lli power(lli a, lli n, lli m) {
  lli ret = 1ll;
  while (n > 0) {
    if (n % 2 == 1) ret = (ret * a) % m;
    a = (a * a) % m;
    n /= 2;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  forn (i, 0, t) {
    lli n, k, m;
    cin >> n >> k >> m;
    lli sum = 0;
    forn(j, 0, n) {
      lli r; cin >> r;
      sum = (sum + r) % m;
    }
    cout << "Case " << i + 1 << ": ";
    cout << (sum % m * power(n, k - 1, m) % m * k % m) % m << '\n';
  }
  return 0;
}
