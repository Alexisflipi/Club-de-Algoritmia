#include <bits/stdc++.h>
using namespace std;

typedef double d;
const int inf = (1<<30);
const int A = 507;

d p;
int n;
d memo[A][A];
bool test[A][A];

d power(d a, int n) {
  d ret = 1.0;
  while (n) {
    if (n % 2 == 1) ret *= a;
    a *= a;
    n /= 2;
  }
  return ret;
}

d dp(int idx, int win) {
  if (idx == n)
    return win;
  d ans = 0.0;
  if (test[idx][win]) 
    return memo[idx][win];
  for (int i = 0; i <= n - idx; i++) {
    ans += (1.0 - p) * power(p, i) * dp(idx + i + 1, max(win, i));
    if (i == n - idx)
      ans += power(p, i) * dp(idx + i, max(win, i));
  }
  test[idx][win] = 1;
  return memo[idx][win] = ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  while (cin >> n >> p) {
    if (!n) break;
    memset(test, 0, sizeof test);
    memset(memo, 0, sizeof memo);
    cout << fixed << setprecision(4);
    cout << dp(0, 0) << '\n';
  }
  return 0;
}
