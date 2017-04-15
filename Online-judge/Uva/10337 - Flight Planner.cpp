#include <bits/stdc++.h>
#define forn(i, n) for (lli i = 0; i < n; i++)
using namespace std;

typedef long long lli;
const lli MAX = 10007;
lli wst[15][MAX];
lli memo[15][MAX];
lli x;
const lli INF = (1<<30);

lli dp(lli dist, lli h) {
  if (h < 0 || h > 9 || dist > x) return INF;
  if (dist == x)
    return (h == 0) ? 0 : INF;
  if (memo[h][dist] != -1) return memo[h][dist];
  lli mini = INF;
  mini = min(mini, 60 - wst[h][dist] + dp(dist + 1, h + 1));
  mini = min(mini, 30 - wst[h][dist] + dp(dist + 1, h));
  mini = min(mini, 20 - wst[h][dist] + dp(dist + 1, h - 1));
  return memo[h][dist] = mini;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  lli t; cin >> t;
  forn(i, t) {
    memset(memo, -1, sizeof memo);
    cin >> x; x /= 100;
    for (lli i = 9; i >= 0; i--)
      forn(j, x)
        cin >> wst[i][j];
    cout << dp(0, 0) << '\n';
    cout << '\n';
  }
  return 0;
}
/*
2
400
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 9 9 1
1 -9 -9 1
1000
9  9  9  9  9  9  9  9  9  9
9  9  9  9  9  9  9  9  9  9
9  9  9  9  9  9  9  9  9  9
9  9  9  9  9  9  9  9  9  9
9  9  9  9  9  9  9  9  9  9
9  9  9  9  9  9  9  9  9  9
7  7  7  7  7  7  7  7  7  7
-5 -5 -5 -5 -5 -5 -5 -5 -5 -5
-7 -3 -7 -7 -7 -7 -7 -7 -7 -7
-9 -9 -9 -9 -9 -9 -9 -9 -9 -9
*/
