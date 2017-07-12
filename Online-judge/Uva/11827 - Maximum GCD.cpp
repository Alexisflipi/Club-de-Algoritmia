#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  cin.ignore();
  while (t--) {
    string s;
    getline(cin, s);
    stringstream ss; ss << s;
    string r;
    vector<int> num;
    while (ss >> r)
      num.push_back(atoi(r.c_str()));
    int maxi = -(1<<30);
    for (int i = 0; i < num.size(); i++)
      for (int j = i + 1; j < num.size(); j++)
        maxi = max(maxi, __gcd(num[i], num[j]));
    cout << maxi << '\n';
  }
  return 0;
}
/*
3
10 20 30 40
7 5 12
125 15 25
*/
