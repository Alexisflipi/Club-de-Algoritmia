#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<string> cad;
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string t = "Aa";
    t[0] += i/26;
    t[1] += i % 26;
    cad.push_back(t);
  }
  vector<int> aux;
  for (int i = 0; i < n - k + 1; i++) {
    string r; cin >> r;
    if (r == "NO")
      cad[i + k - 1] = cad[i];
  }
  for (int i = 0; i < cad.size(); i++) {
    if (i > 0) cout << ' ';
    cout << cad[i] << ' ';
  }
  cout << '\n';
  return 0;
}
