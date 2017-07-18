#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> ii;

lli x, y, d;

void e_ext(lli a, lli b) {
  if (b == 0) {x = 1; y = 0; d = a; return; }
  e_ext(b, a % b);
  lli x1 = y;
  lli y1 = x - (a/b) * y;
  x = x1;
  y = y1;
}

lli n1, c1;
lli n2, c2, r;

lli f(lli m) {
  lli u = (x * r) + (n2/d) * m;
  lli v = (y * r) - (n1/d) * m;
  return c1 * u + c2 * v;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  lli n;
  while (cin >> n and n) {
    cin >> c1 >> n1;
    cin >> c2 >> n2;
    e_ext(n1, n2);
    if (n % d != 0) {
      cout << "failed\n";
      continue;
    }
    r = n/d;
    lli a = ceil(double(-x * r * d)/double(n2));
    lli b = floor(double(y * r * d)/double(n1));
    if (a > b) {
      cout << "failed\n";
      continue; 
    }
    lli mini = (1ll<<60);
    ii ans;

    lli lo = a, hi = b;
    while (1) {
      if (abs(hi - lo) < 10) {break;}
      lli ml = lo + (hi - lo)/3;
      lli mr = hi - (hi - lo)/3;
      if (f(ml) <= f(mr)) hi = mr;
      else lo = ml;
    }
    for (lli i = lo; i <= hi; i++) {
      lli u = (x * r) + (n2/d) * i;
      lli v = (y * r) - (n1/d) * i;
      if (c1 * u + c2 * v < mini)
        mini = c1 * u + c2 * v,
        ans = ii(u, v);
    }
    cout << ans.first << " " << ans.second << '\n';
  }
  return 0;
}
/*

*/
