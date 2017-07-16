#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define forn(i, a, b) for (lli i = a; i < b; i++)
#define fst first
#define snd second
using namespace std;

typedef long long lli;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = (1<<30);
const int MAX = 2 * 1e6 + 7;
int phi[MAX];

void criba_euler_phi(){
  for (int k = 1; k < MAX; k++)
    phi[k] = k;
  for (int i = 2; i < MAX; i++){
    if (phi[i] == i)
      for (int j = i; j < MAX; j += i){
        phi[j] /= i;
        phi[j] *= i - 1;
      }
  }
}
int acu[MAX];
int memo[MAX];
int depth[MAX];

int dp(int n) {
  if (n == 1) return 0;
  if (memo[n] != -1) return memo[n];
  int ans = 0;
  ans += dp(phi[n]) + 1;
  return memo[n] = ans;
}

void pre() {
  memset(memo, -1, sizeof memo);
  forn(i, 1, MAX)
    depth[i] = dp(i);
  forn(i, 1, MAX)
    acu[i] = acu[i - 1] + depth[i];
}

int main() {
  criba_euler_phi();
  pre();
  int t; cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << acu[b] - acu[a - 1] << '\n';
  }
  return 0;
}
