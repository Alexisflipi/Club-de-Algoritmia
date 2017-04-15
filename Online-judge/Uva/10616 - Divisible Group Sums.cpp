#include <bits/stdc++.h>
#define forn(i, n) for(lli i = 0; i < n; i++)
using namespace std;

typedef long long lli;
const lli MAX = 205;
lli num[MAX];
lli n, q;
lli d, m;
lli memo[205][15][25];

lli mod(lli a, lli b) {
  return (a >= 0) ? a % b : (b - abs(a % b)) % b;
}

lli dp(lli idx, lli tkn, lli r) {
  if (idx == n)
    return (r == 0 && tkn == m) ? 1 : 0;
  if (tkn > m || idx > n) return 0;
  if (memo[idx][tkn][r] != -1) return memo[idx][tkn][r];
  return memo[idx][tkn][r] = dp(idx + 1, tkn, r) + dp(idx + 1, tkn + 1, mod(r + num[idx], d));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  lli s = 0;
  while (cin >> n >> q and n and q) {
    forn(i, n) cin >> num[i];
    cout << "SET " << ++s << ":\n"  ;
    forn(i, q) {
      memset(memo, -1, sizeof memo);
      cin >> d >> m;
      cout << "QUERY " << i + 1 << ": ";
      cout << dp(0, 0, 0) << '\n';
    }
  }
  return 0;
}
/*
10 2
1
2
3
4
5
6
7
8
9
10
5 1
5 2

5 1
2
3
4
5
6
6 2
0 0
*/
