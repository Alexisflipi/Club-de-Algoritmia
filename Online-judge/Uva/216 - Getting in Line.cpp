#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef double d;
typedef pair<d, d> ii;
typedef vector<ii> vii;

const d INF = 1e10;
const int A = 10;
int n;
vii coor;
d memo[A][2000];
d dist[A][A];
pair<ii, ii> mapeo[A][2000];
bool test[A][2000];

d tsp(int pos, int mask){
  if (mask == (1<<n) - 1)
    return 0.0;
  if (memo[pos][mask] != -1)
    return memo[pos][mask];
  d ans = INF;
  for (int i = 0; i < n; i++){
    if (mask & (1<<i) || pos == i || test[pos][mask]) continue;
    test[pos][mask]  = 1;
    ans = min(ans, dist[pos][i] + tsp(i, mask|(1<<i)));
    test[pos][mask] = 0;
  }
  return memo[pos][mask] = ans;
}

d p(d r) {
  return r * r;
}

d di(ii a, ii b) {
  return sqrt(p(a.fst - b.fst) + p(a.snd - b.snd));
}

//Reconstruccion dp para tsp
void re_dp(int pos, int mask) {
  if (mask == (1 << n) - 1) return; // similar a los casos bases
  for (int i = 0; i < n; i++) { // cual es el modelo optimo
    if (mask & (1<<i) || pos == i) continue;
    d r = dist[pos][i] + tsp(i, mask|(1<<i));
    if (r == memo[pos][mask]) {
        ii x = mapeo[pos][i].fst;
        ii y = mapeo[pos][i].snd;
        cout << fixed;
        cout << setprecision(0);
        cout << "Cable requirement to connect ("<<x.fst<<","<<x.snd<<") to ("<<y.fst<<","<<y.snd<<") is " << fixed << setprecision(2) << dist[pos][i] << " feet.\n";
        re_dp(i, mask|(1<<i)); // recursar a este estado
        break; // no es valido visitar otros estados
    }
  }
}

void makeset() {
  for (int i = 0; i < A; i++)
    for (int j = 0; j < 2000; j++)
      memo[i][j] = -1.0, test[i][j] = false;
}

int main() {
  //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 0;
  while (cin >> n and n) {
    d x, y;
    for (int i = 0; i < n; i++)
      cin >> x >> y, coor.push_back(ii(x, y));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        dist[i][j] = di(coor[i], coor[j]) + 16.0;
        mapeo[i][j] = make_pair(coor[i], coor[j]);
      }

    d ans = INF;
    int idx = 0;
    for (int i = 0; i < n; i++) {
      makeset();
      d aux = tsp(i, (1<<i));
      if (aux < ans)
        ans = aux, idx = i;
    }
    makeset();
    ans = tsp(idx, (1<<idx));
    cout << "**********************************************************\n";
    cout << "Network #" << ++t << '\n';
    re_dp(idx, (1<<idx));

    cout << fixed;
    cout << setprecision(2);
    cout << "Number of feet of cable required is " << ans << ".\n";
    coor.clear();
  }
  return 0;
}
/*
6
5 19
55 28
38 101
28 62
111 84
43 116
5
11 27
84 99
142 81
88 30
95 38
3
132 73
49 86
72 111
0
*/
