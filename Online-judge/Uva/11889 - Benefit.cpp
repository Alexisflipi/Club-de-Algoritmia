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

const int MAX = 4000;
vi primes;
bool m[MAX];

void criba() {
  for (int i = 3; i < MAX; i += 2) m[i] = 1;
  for (int i = 3; i * i < MAX; i += 2)
    if (m[i]) for (int j = i * i; j < MAX; j += i) m[j] = 0;
  primes.pb(lli(2));
  for (int i = 3; i < MAX; i += 2)
    if (m[i]) primes.pb(lli(i));
}

lli power(lli a, lli n) {
  lli ret = 1;
  while (n > 0) {
    if (n % 2 == 1) ret *= a;
    a *= a;
    n /= 2;
  }
  return ret;
}

vii des(lli n) {
  vii ans;
  int idx = 0;
  lli r = n;
  while (idx < primes.size() &&
    primes[idx] * primes[idx] <= n) {
    lli p = primes[idx++];
    if (r % p == 0) {
      lli e = 0;
      while (r % p == 0) e++, r /= p;
      ans.push_back(ii(p, e));
    }
  }
  if (r > 1)
    ans.push_back(ii(r, 1));
  return ans;
}

lli solve(vii a, vii c) {
  map<lli, lli> factor_c;
  map<lli, lli> factor_a;
  for (auto &it : c)
    factor_c[it.fst] = it.snd;
  for (auto &it : a)
    factor_a[it.fst] = it.snd;
  lli ans = 1;
  for (auto &it : c) {
    if (factor_a.find(it.fst) == factor_a.end()) {
      ans = ans * power(it.fst, it.snd);
    } else {
      lli a = factor_a[it.fst];
      factor_a[it.fst] = 0;
      if (it.snd != a)
        ans = ans * power(it.fst, it.snd);
    }
  }
  for (auto &it : factor_a)
    if (it.snd > 0) ans = -1;
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  criba();
  int t; cin >> t;
  while (t--) {
    lli A, C;
    cin >> A >> C;
    vii a = des(A);
    vii c = des(C);
    lli ans = solve(a, c);
    if (ans == -1) cout << "NO SOLUTION\n";
    else cout << ans << '\n';
  }
  return 0;
}
