#include <bits/stdc++.h>
using namespace std;

const int INF = (1<<30);

int count(string &s) {
  int idx = 0;
  int r = 0;
  while (1) {
    idx = s.find("VK", idx);
    if (idx == -1) break;
    idx += 2;
    r++;
  }
  return r;
}

int main() {
  string s; cin >> s;
  int cont = -INF;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'V') {
      s[i] = 'K';
      cont = max(cont, count(s));
      s[i] = 'V';
    } else {
      s[i] = 'V';
      cont = max(cont, count(s));
      s[i] = 'K';
    }
  }
  cout << max(cont, count(s)) << '\n';
  return 0;
}
