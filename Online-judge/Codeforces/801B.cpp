#include <bits/stdc++.h>
using namespace std;

int main() {
  string x, y;
  cin >> x >> y;
  bool flag = 1;
  for (int i = 0; i < x.size(); i++) {
    if (x[i] < y[i]) {flag = 0; break;}
  }
  cout << ((flag) ? y : "-1") << '\n';
  return 0;
}
