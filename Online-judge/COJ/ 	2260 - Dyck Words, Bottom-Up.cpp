#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
const lld MOD = 1000000007;
const lld A = 2010;

lld N;
//lld memo[A][A];
lld dp[A][A];

/*lld dp(lld X, lld Y){
  if (Y > X || X > N || Y > N)
    return 0;
  if (X == N && Y == N)
    return 1;
  if (memo[X][Y] != -1)
    return memo[X][Y];
  return memo[X][Y] = (dp(X + 1, Y) % MOD + dp(X, Y + 1) % MOD) % MOD;
}*/

lld dpi(){
  dp[0][0] = 1;
  for (int x = 1; x <= N; x++){
    for (int y = 0; y <= N; y++){
      if (y > x) continue;
      if (y == 0)
        dp[x][y] = dp[x - 1][y] % MOD;
      else
        dp[x][y] = (dp[x][y - 1] + dp[x - 1][y]) % MOD;
    }
  }
  return dp[N][N] % MOD;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  lld T;
  cin >> T;
  while (T--){
    //memset(memo, -1, sizeof memo);
    cin >> N;
    cout << dpi() << "\n";
  }
  return 0;
}
/*
2
2
10
*/
