#include <bits/stdc++.h>
#define forn(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int power(int a, int n) {
  int ret = 1;
  while (n > 0) {
    if (n % 2 == 1) ret *= a;
    a *= a;
    n /= 2;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s;
  while (cin >> s) {
    if (s.size() == 1 && s == "0") break;
    reverse(s.begin(), s.end());
    int sum = 0;
    forn(i, 0, s.size()) {
      sum += (s[i] - '0') * (power(2, i + 1) - 1);
    }
    cout << sum << '\n';
  }
  return 0;
}
