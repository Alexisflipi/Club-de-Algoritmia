#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<lld, lld> ii;
typedef vector<ii> vii;
typedef vector<lld> vi;

const int MAX = 1e6 + 5;
vi ans;

vi divisores(){
  vector<vi> divisors(MAX, vi());
  int cont = 0;
  for (int i = 1; i < MAX; i++)
    for (int j = i; j < MAX; j += i)
      divisors[j].push_back(i);
  //Ejemplo: divisores de 45:
  vi r(MAX);
  for (int i = 1; i < MAX; i++)
    r[i] = divisors[i].size();
  return r;
}

void pre() {
  vi r = divisores();
  ans = vi(MAX);
  for (int i = 1; i < MAX - 2; i++)
    (r[i] >= r[ans[i - 1]]) ? ans[i] = i : ans[i] = ans[i - 1];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  pre();
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    cout << ans[n] << '\n';
  }
  return 0;
}
