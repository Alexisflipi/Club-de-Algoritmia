#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef vector<lld> vi;

vi solve(int n, int k) {
  lld cont = 1;
  lld res = 1;
  lld impar = 1;
  vi r;
  for (lld i = 1; i <= n; i++) {
    cont += k;
    if (cont > n) {
      cont %= n;
      impar += 2;
      r.push_back(res += (impar - 1));
    } else {
      r.push_back(res += impar);
    }
  }
  r[r.size() - 1]--;
  return r;
}

int main() {
  lld n, k;
  cin >> n >> k;
  k = min(k, n - k);
  vi ans = solve(n, k);
  for (lld i = 0; i < ans.size(); i++) 
    cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
