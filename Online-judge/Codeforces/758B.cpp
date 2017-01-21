#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  string aux = "RBYG";
  map<char, int> ida;
  map<int, char> reg;
  for (int i = 0; i < aux.size(); i++)
    ida[aux[i]] = i, reg[i] = aux[i];

  map<int, char> m;
  for (int i = 0; i < 4; i++)
    m[i] = 'w';
  vector<int> c(4);
  for (int i = 0; i < s.size(); i++) {
    int idx = i % 4;
    if (s[i] == '!')
      c[idx]++;
    else
      m[idx] = s[i];
  }
  vector<int> ans(4);
  for (int i = 0; i < 4; i++)
    ans[ida[m[i]]] = c[i];
  
  for (auto &it : ans)
    cout << it << " ";
  cout << "\n";
  return 0;
}
