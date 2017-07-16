#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define forn(i, a, b) for (lli i = a; i < b; i++)
#define fst first
#define snd second
using namespace std;

typedef long long lli;
typedef vector<lli> vi;
typedef pair<lli, lli> ii;
typedef vector<ii> vii;

const int MOD = 10;
const int MAX = 1e6 + 2;
const int TAM = 1e6 + 2;

vi primes;
bool m[MAX];

void criba() {
  for (int i = 3; i < TAM; i += 2) m[i] = 1;
  primes.pb(2ll);
  for (int i = 3; i * i < TAM; i += 2)
    if (m[i]) for (int j = i * i; j < TAM; j += i) m[j] = 0;
  for (int i = 3; i < TAM; i += 2)
    if (m[i]) primes.pb(lli(i));
}

lli power(lli a, lli n, lli mod) {
  lli ret = 1;
  while (n > 0) {
    if (n % 2 == 1) 
      ret = (ret * a) % mod;
    a = (a * a) % mod;
    n /= 2;
  }
  return ret;
}

lli solve(lli n) {
  lli sum = 1;
  lli one = 0;
  lli two = 0;
  for (auto &p : primes) {
    if (p > n) break; 
    lli cont = 0;
    for (lli j = 1; j <= n; j *= p, cont++);
    if (p == 2) {two = cont - 1; continue;}
    if (p == 5) {one = cont - 1; continue;}
    sum = (sum * power(p, cont - 1, MOD)) % MOD;
  }
  sum = (sum * power(2ll, two - one, MOD)) % MOD;
  return sum;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  lli n;
  criba();
  while (cin >> n and n)
    cout << solve(n) << '\n';
  return 0;
}
