#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
const lld MOD = 1000000007;
lld f(char c){
  if (c <= 'Z' && c >= 'A')
    return c - 'A' + 10;
  if (c <= 'z' && c >= 'a')
    return c - 'a' + 36;
  if (c <= '9' && c >= '0')
    return c - '0';
  if (c == '-')
    return 62;
  return 63;
}

lld mapeo(string s){
  lld ans = 1;
  for (lld i = 0; i < s.size(); i++){
    lld r = f(s[i]);
    for (lld j = 0; j < 6; j++)
      if ((r & (1<<j)) == 0)
        ans = (ans * 3) % MOD;
  }
  return ans;
}

int main(){
  string s;
  cin >> s;
  cout << mapeo(s) << "\n";
  return 0;
}
