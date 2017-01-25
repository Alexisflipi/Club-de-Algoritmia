#include <bits/stdc++.h>
using namespace std;

map<int, string> bus;
set<string> ans;
set<int> temp;
string r;

void f(string s, int idx) {
  if (s.size() == r.size()) {
    ans.insert(s);
    return;
  }
  if (temp.find(idx) != temp.end())
    for (int j = 0; j < 4; j++)
      f(s + bus[j], idx + 1);
  else 
    f(s + r[idx], idx + 1);
}

int main() {
  int T; cin >> T;
  bus[0] = "A";
  bus[1] = "G";
  bus[2] = "T";
  bus[3] = "C";
  while (T--) {
    temp.clear();
    ans.clear();
    int n, k;
    cin >> n >> k;
    cin >> r;
    for(int i = 0; i < (1<<n); i++) {
      int cont = 0;
      for (int j = 0; j < n; j++)
        if (i & (1<<j))
          temp.insert(j);
      if (temp.size() == k)
        f("", 0);
      temp.clear();
    }
    cout << ans.size() << "\n";
    for (auto &it : ans)
      cout << it << "\n";
  }
  return 0;
}
/*
1
3 1
AAA
*/
