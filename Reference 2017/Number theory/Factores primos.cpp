#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<lld, lld> F;
typedef vector<F> vi;

vi PrimeFactors(lld n){
  lld c = 0;
  vi factors;
  while (!(n & 1)) ++c, n >>= 1;
  if (c) factors.push_back(F(2, c)), c = 0;
  for (lld i = 3; i * i <= n; i += 2){
    while(!(n % i)) ++c, n /= i;
    if (c) factors.push_back(F(i, c)), c = 0;
  }
  if (n > 1) factors.push_back(F(n, 1));
  return factors;
}


int main(){
  int N; cin >> N;
  vi ans = PrimeFactors(N);
  for (auto p : ans)
    cout << p.first << " " << p.second << "\n";
}
