#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
typedef pair<Long, Long> Factor;
typedef vector<Factor> vi;

vi FactoresPrimos(Long a){
  Long conteo = 0;
  vi factores;
  while (!(a & 1)) ++conteo, a >>= 1;
  if (conteo) factores.push_back(Factor(2, conteo)), conteo = 0;
  Long raiz = sqrt(a);
  for (Long i = 3; i <= raiz; i += 2){
    while(!(a % i)) ++conteo, a /= i;
    if (conteo) factores.push_back(Factor(i, conteo)), conteo = 0;
  }
  if (a > 1) factores.push_back(Factor(a, 1));
  return factores;
}


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  Long N;
  while (cin >> N and N){
    vi num = FactoresPrimos(abs(N));
    Long gcd = 0;
    for (auto it : num){
      gcd = __gcd(gcd, it.second);
    }
    if(N < 0)
    while(gcd % 2 == 0) gcd /= 2;
    cout << gcd << "\n";
  }
}
/*
17
1073741824
25
0
*/
