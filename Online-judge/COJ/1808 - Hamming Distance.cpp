#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  while (cin >> s) {
    if (s == "X") break;
    string r; cin >> r;
    int cont = 0;
    for (int i = 0; i < r.size(); i++)
      if (r[i] == s[i]) continue; else cont++;
    cout << "Hamming distance is " << cont << ".\n";
  }
  return 0;
}
