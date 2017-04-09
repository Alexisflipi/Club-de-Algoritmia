#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
const lld MAX = 55;
lld m;
lld memo[MAX][MAX];

lld dp(lld n, lld k) { 
  if (n == 0 && k == 0) return 1;
  if (n <= 0 || k <= 0) return 0;
  if (memo[n][k] != -1) return memo[n][k];
  lld ans = 0;
  for (lld i = 1; i <= m; i++)
    ans += dp(n - i, k - 1);
  return memo[n][k] = ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  lld n, k;
  while (cin >> n >> k >> m) {
    memset(memo, -1, sizeof memo);
    cout << dp(n, k) << '\n';
  }
  return 0;
}
