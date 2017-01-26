#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

map<lld, lld> m;
map<lld, lld> ans;
void divisors(lld n) {
  for (lld i = 1; i * i <= n; i++)
    if (n % i == 0)
      m[n/i]++, m[i]++;
  lld cont = 0;
  for (auto &it : m)
    ans[++cont] = it.first;
}

int main() {
  lld n, k;
  cin >> n >> k;
  divisors(n);
  if (k > m.size())
    cout << "-1\n";
  else
    cout << ans[k] << "\n";
  return 0;
}
