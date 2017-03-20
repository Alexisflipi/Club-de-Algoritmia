#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
const lld MAXN = 1000007;
lld hist[MAXN];

//Pila incremental
//Time complexity: O(n)

lld getMaxArea(lld n){
  stack<lld> s;
  lld max_area = 0;
  lld tp;
  lld area_with_top;
  lld i = 0;
  while (i < n) {
    if (s.empty() || hist[s.top()] <= hist[i])
      s.push(i++);
    else {
      tp = s.top();
      s.pop();
      area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
      max_area = max(max_area, area_with_top);
    }
  }
  while (!s.empty()){
    tp = s.top(); s.pop();
    area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
    max_area = max(max_area, area_with_top);
  }
  return max_area;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  lld n;
  cin >> n;
  for (lld i = 0; i < n; i++)
    cin >> hist[i];
  cout << getMaxArea(n) << "\n";
  return 0;
}
