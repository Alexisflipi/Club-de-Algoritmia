#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

lli f(lli n, lli m) {
  lli ans = 0;
  for (lli i = 1; i + 8 - 1 <= m; i++) {
    lli aux = n;
    if (i % 2 != 1) aux--;
    ans += (aux - 8)/2 + 1;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  lli n, m, c;
  while (cin >> n >> m >> c) {
    if (n == 0 && m == 0 && c == 0) break;
    if (n < m) swap(n, m);
    if (c == 1)
      cout << f(n, m) << '\n';
    else
      cout << f(n, m - 1) + ((n == 8) ? 0 : (n - 9)/2 + 1) << '\n';
  }
  return 0;
}
