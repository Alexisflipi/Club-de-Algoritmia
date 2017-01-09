#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> solve(vector<vii> &m, int r, int c){
  vector<vii> ans(c + 1);
  for (int i = 0; i < r; i++)
    for (auto &it : m[i + 1])
      ans[it.first].push_back(ii(i + 1, it.second));
  return ans;
}

void print(vector<vii> &ans, int r, int c){
  cout << c << " " << r << "\n";
  for (int i = 0; i < c; i++){
    int l = ans[i + 1].size();
    cout << l;
    if (l == 0) { cout << "\n\n"; continue; }
    for (auto &it : ans[i + 1])
      cout << " " << it.first;
    cout << "\n";
    for (int j = 0; j < l - 1; j++)
      cout << ans[i + 1][j].second << " ";
    cout << ans[i + 1][l - 1].second << "\n";
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int r, c;
  while (cin >> r >> c){
    vector<vii> m(r + 1);
    for (int i = 0; i < r; i++){
      int num; cin >> num;
      for (int j = 0; j < num; j++){
        int a; cin >> a;
        m[i + 1].push_back(ii(a, 0));
      }
      for (int j = 0; j < num; j++){
        int a; cin >> a;
        m[i + 1][j] = ii(m[i + 1][j].first, a);
      }
    }
    vector<vii> ans = solve(m, r, c);
    print(ans, r, c);
  }
  return 0;
}
/*
4 3
3 1 2 3
1 3 2
2 2 3
4 -1
0

3 1 2 3
5 -2 11

4 3
2 2 3
3 2
2 2 3
4 -1
0
2 2 3
-2 11
*/
