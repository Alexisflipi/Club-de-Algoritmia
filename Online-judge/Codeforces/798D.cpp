#include <bits/stdc++.h>
#define fore(i, a, b) for(lli i = a, t = b; i < t; ++i)
#define fst first
#define snd second
using namespace std;

typedef long long lli;
const lli MAX = 100005;
typedef pair<lli, lli> ii;
lli numa[MAX];
lli numb[MAX];
pair<ii, lli> x[MAX];
lli suma, sumb;

bool valid(lli n) {
  lli acua = 0;
  lli acub = 0;
  fore(i, 0, n/2 + 1)
    acua += x[i].fst.fst, acub += x[i].fst.snd;
  return 2 * acua > suma && 2 * acub > sumb;
}

int main() {
  lli n; cin >> n;
  fore(i, 0, n)
    cin >> numa[i], suma += numa[i];
  fore(i, 0, n)
    cin >> numb[i], sumb += numb[i];
  fore(i, 0, n)
    x[i] = make_pair(ii(numa[i], numb[i]), i);
  while (!valid(n)) random_shuffle(x, x + n);
  cout << n/2 + 1 << '\n';
  fore(i, 0, n/2 + 1) {
    if (i > 0) cout << ' ';
    cout << x[i].snd + 1;
  }
  cout << '\n';
  return 0;
}
