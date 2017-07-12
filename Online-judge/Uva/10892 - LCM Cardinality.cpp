#include <bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;

typedef long long lli;
typedef vector<lli> vi;

vi f(lli n) {
  set<lli> bus;
  for (lli i = 1; i * i <= n; i++)
    if (n % i == 0)
      bus.insert(i), bus.insert(n/i);
  vi aux;
  for (auto &it : bus)
    aux.pb(it);
  return aux;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  lli n;
  while (cin >> n and n) {
    vi d = f(n);
    lli ans = 0;
    for (auto &a : d)
      for (auto &b : d)
        if (n == a * (b/__gcd(a,b)) && a <= b) ans++;
    cout << n << " " << ans << '\n';
  }
  return 0;
}
