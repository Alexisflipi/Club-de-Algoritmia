#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if (!a && !b) {
    cout << "NO\n";
    return 0;
  }
  (abs(a - b) == 1 || abs(a- b) == 0) ? cout << "YES\n" : cout << "NO\n";
  return 0;
}
