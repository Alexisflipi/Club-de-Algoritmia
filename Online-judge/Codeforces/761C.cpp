#include <bits/stdc++.h>
using namespace std;

const int MAX = 55;
const int INF = (1 << 30);
int n, m;
string s[MAX];
int memo[MAX][MAX][MAX][MAX];

bool check1(char c) {
  return (c - '0' <= 9 && c - '0' >= 0) ? 1 : 0;
}

bool check2(char c) {
  return (c <= 'z' && c >= 'a') ? 1 : 0;
}

bool check3(char c) {
  return (c == '&' || c == '*' || c == '#') ? 1 : 0;
}


int dp(int idx, int a, int b, int c) {
  if (idx == n && a > 0 && b > 0 && c > 0)
    return 0;
  if (idx == n && (a <= 0 || b <= 0 || c <= 0))
    return INF;
  if (memo[idx][a][b][c] != -1)
    return memo[idx][a][b][c];
  int ans = INF;
  for (int i = 0; i < m; i++) {
    char f = s[idx][i];
    (check1(f)) ? ++a : a; (check2(f)) ? ++b : b; (check3(f)) ? ++c : c;
    ans = min(ans, i + dp(idx + 1, a, b, c));
    (check1(f)) ? --a : a; (check2(f)) ? --b : b; (check3(f)) ? --c : c;
    f = s[idx][m - i];
    (check1(f)) ? ++a : a; (check2(f)) ? ++b : b; (check3(f)) ? ++c : c;
    ans = min(ans, i + dp(idx + 1, a, b, c));
    (check1(f)) ? --a : a; (check2(f)) ? --b : b; (check3(f)) ? --c : c;
  }
  return memo[idx][a][b][c] = ans; 
}

int main() {
  memset(memo, -1, sizeof memo);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> s[i];
  cout << dp(0, 0, 0, 0) << "\n";
  return 0;
}
/*
5 5
#*&#*
*a1c&
&q2w*
#a3c#
*&#*&
*/
