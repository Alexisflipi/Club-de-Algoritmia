#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

const int MAX = 5001;
const int INF = (1<<30);

int n, m, T;
int p[MAX][MAX];
int memo[MAX][MAX];

vector<ii> ady[MAX];

void printpath(int u, int i) {
  if (i == 0) return;
  printpath(p[u][i], i - 1);
  cout << u + 1;
  if (u != n) cout << ' ';
}

int dp(int u, int d) {
  if (d <= 0) return INF;
  if (memo[u][d] != -1) return memo[u][d];
  int ans = INF; int tkn = -1;
  for (auto &v : ady[u]) {
    int r = v.snd + dp(v.fst, d - 1);
    if (r < ans) tkn = v.fst, ans = r;
  }
  p[u][d] = tkn;
  return memo[u][d] = ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m >> T;
  memset(memo, -1, sizeof memo);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    ady[--v].push_back(mp(--u, w));
  }
  memo[0][1] = 0;
  int idx = 0;
  for (int i = 1; i <= n; i++)
    if (dp(n - 1, i) <= T) idx = i;

  cout << idx << '\n';
  printpath(n - 1, idx);
  return 0;
}
/*
6 6 7
1 2 2
1 3 3
3 6 3
2 4 2
4 6 2
6 5 1

*/
