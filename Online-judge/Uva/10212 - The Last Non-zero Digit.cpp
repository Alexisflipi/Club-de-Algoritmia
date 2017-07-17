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

const lli oo = (1ll<<60);
const int MAX = 3 * 1e7 + 5;

vi primes;
int m[MAX];

void criba() {
  for (int i = 3; i < MAX; i += 2) m[i] = 1;
  for (int i = 3; i * i < MAX; i += 2)
    if (m[i]) for (int j = i * i; j < MAX; j += i) m[j] = 0;
  primes.pb(2ll);
  for (int i = 3; i < MAX; i += 2)
    if (m[i]) primes.pb(lli(i));
}

lli get_p(lli n, lli p) {
  lli res = 0;
  for (lli pw = p; pw <= n; pw *= p)
    res += n/pw;
  return res;
}

vi des(lli n) {
  vi ans;
  for (int i = 0; primes[i] <= n; i++)
    ans.pb(get_p(n, primes[i]));
  return ans;
}

lli power(lli a, lli n, lli mod) {
  lli ret = 1;
  while (n > 0) {
    if (n % 2 == 1) ret = (ret * a) % mod;
    a = (a * a) % mod;
    n /= 2;
  }
  return ret;
}

lli solve(lli n, lli m) {
  vi u = des(n);
  vi v = des(n - m);
  vi f;
  forn(i, 0, u.size())
    if (i < v.size()) f.pb(u[i] - v[i]);
    else f.pb(u[i]);
  lli p = 0;
  if (f.size() > 2)
    p = min(f[0], f[2]), f[0] -= p, f[2] -= p;
  lli mod = 10ll;
  lli ans = 1;
  forn(i, 0, f.size())
    ans = (ans % mod * power(primes[i], f[i], mod) % mod) % mod;
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  criba();
  lli n, m;
  while (cin >> n >> m) {
    cout << solve(n, m) << '\n';
  }
  return 0;
}
