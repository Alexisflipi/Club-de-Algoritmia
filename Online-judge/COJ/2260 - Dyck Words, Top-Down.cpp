#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
const lld MOD = 1000000007;
const lld A = 2010;

lld N;
lld memo[A][A];

lld dp(lld X, lld Y){
  if (Y > X || X > N || Y > N)
    return 0;
  if (X == N && Y == N)
    return 1;
  if (memo[X][Y] != -1)
    return memo[X][Y];
  return memo[X][Y] = (dp(X + 1, Y) % MOD + dp(X, Y + 1) % MOD) % MOD;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  lld T;
  cin >> T;
  while (T--){
    memset(memo, -1, sizeof memo);
    cin >> N;
    cout << dp(0, 0) << "\n";
  }
  return 0;
}
