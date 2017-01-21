#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
typedef vector<int> vi;
int dp[1000010];

int count_ways(vi & stick, int L){
  dp[0] = 1;
  int s = stick[0];
  int t = stick[1];
  for (int i = 0; i <= L; i++){
    int p = i - s;
    int q = i - t;
    if (p >= 0 && q >= 0)
      dp[i] = (dp[p] + dp[q]) % MOD;
    else
      if (p < 0 && q >= 0)
        dp[i] = dp[q] % MOD;
      else
        if (p >= 0 && q < 0)
          dp[i] = dp[p] % MOD;
  }
  return dp[L] % MOD;
}

int main(){
  int L, s, t;
  cin >> L >> s >> t;
  vi stick{s, t};
  cout << count_ways(stick, L) << "\n";
}
/*
6 2 3
1000000 2 3
*/
