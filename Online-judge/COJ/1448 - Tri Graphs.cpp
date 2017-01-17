#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

const lld MAX = 100007;
const lld A = 3;

lld m[MAX][A];
lld dp[MAX][A];

lld solvedp(lld N){
  /*for (lld i = 0; i < A; i++)
    dp[0][i] = m[0][i];*/

  dp[1][0] = m[1][0] + m[0][1];
  dp[1][1] = m[1][1] + min(m[0][1], min(dp[1][0], m[0][1] + m[0][2]));
  dp[1][2] = m[1][2] + min(m[0][1], min(dp[1][1], m[0][1] + m[0][2]));

  for (lld i = 2; i < N; i++){
    for (lld j = 0; j < A; j++){
      if (j == 0)
        dp[i][j] = m[i][j] + min(dp[i - 1][j], dp[i - 1][j + 1]);
      if (j == 1)
        dp[i][j] = m[i][j] + min(min(dp[i][j - 1], dp[i - 1][j - 1]), min(dp[i - 1][j], dp[i - 1][j + 1]));
      if (j == 2)
        dp[i][j] = m[i][j] + min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j]));
    }
  }
  return dp[N - 1][1];
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lld N;
  lld ca = 0;
  while (cin >> N and N){
    ca++;
    for (lld i = 0; i < N; i++)
      cin >> m[i][0] >> m[i][1] >> m[i][2];

    lld ans = solvedp(N);
    cout << ca << ". " << ans << "\n";
  }
}
/*
4
13 7 5
7 13 6
14 3 12
15 6 16
4
13 7 5
7 13 6
14 3 12
15 4 16
0
*/
