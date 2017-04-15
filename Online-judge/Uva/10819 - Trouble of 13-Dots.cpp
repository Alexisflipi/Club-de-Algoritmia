#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;

const int MAX = 10007;
const int INF = (1<<30);
const int A = 105;
int m, n;
int cost[A];
int val[A];
int memo[A][MAX];

int dp(int idx, int money) {
  if (idx == n) {
    if (money <= m || (money > 2000 && money <= m + 200)) return 0;
    return -INF;
  }
  if (memo[idx][money] != -1) return memo[idx][money];
  int ans = -INF;
  int buy = money + cost[idx];
  if (buy <= m + 200)
    ans = max(ans, val[idx] + dp(idx + 1, buy));
  ans = max(ans, dp(idx + 1, money));
  return memo[idx][money] = ans;
}
int main() {
  while (cin >> m >> n) {
    memset(memo, -1, sizeof memo);
    forn(i, n)
      cin >> cost[i] >> val[i];
    cout << dp(0, 0) << '\n';
  }
  return 0;
}
/*
2500 4
100 2
100 3
200 3
2600 10


*/
