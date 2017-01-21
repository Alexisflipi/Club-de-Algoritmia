#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int power(int a, int n) {
  int ret = 1;
  while (n > 0) {
    if (n % 2 == 1) ret *= a;
    a *= a;
    n /= 2;
  }
  return ret;
}

vector<vi> solve(vi num, int n) {
  vector<vi> ans(n);
  int k = n - 2;
  int root = power(2, n) - 1;
  int h = 0;
  ans[h++].push_back(root>>1);
  while (k >= 0) {
    int r = power(2, k);
    for (auto &v : ans[h - 1]) {
      ans[h].push_back(v - r);
      ans[h].push_back(v + r);
    }
    h++;
    k--;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
  
  int n; cin >> n;
  int r = power(2, n) - 1;
  vi num(r, 0);
  for (int i = 0; i < r; i++)
    cin >> num[i];
  vector<vi> ans = solve(num, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < ans[i].size() - 1; j++)
      cout << num[ans[i][j]] << " ";
    cout << num[ans[i][ans[i].size() - 1]] << "\n";
  }
  return 0;
}
/*
3
1 6 4 3 5 2 7
*/
