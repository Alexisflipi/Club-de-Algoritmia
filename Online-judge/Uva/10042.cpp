#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
const lld MAX = 50000;
bool m[MAX];
vector<lld> prime;

void criba(){
  for (lld i = 3; i < MAX; i +=2 ) m[i] = true; m[2] = true;
  for (lld i = 3; i * i < MAX; i += 2)
    if (m[i]) for (lld j = i * i; j < MAX; j += i) m[j] = false;
  for (lld i = 2; i < MAX; i++) if (m[i])
      prime.push_back(i);
}

lld sum(lld p){
  stringstream ss;
  ss << p; string r;
  ss >> r;
  lld acu = 0;
  for (auto c : r)
    acu += (c - '0');
  return acu;
}

bool isprime(lld n){
  for (auto p : prime)
    if (n % p == 0)
      return false;
  return true;
}

lld desc(lld n){
  lld acu = 0;
  lld idx = 0;
  lld t = n;
  while (idx < prime.size() && prime[idx] * prime[idx] <= n){
    while (n % prime[idx] == 0){
      acu += sum(prime[idx]);
      n /= prime[idx];
    }
    idx++;
  }
  if (t == n) return true;
  if (n > 1)
    acu += sum(n);
  return acu;
}

bool check(lld n){
  if (sum(n) == desc(n)){
    if (isprime(n)) return false;
    cout << n << "\n";
    return false;
  }
  return true;
}

int main(){
  criba();
  lld T; cin >> T;
  while (T--){
    lld N; cin >> N; N++;
    while (check(N)) N++;
  }
  return 0;
}
