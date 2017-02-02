#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

bool solve(vi a, vi b, int h) {
  vi simula(h + 1, 0);
  for (auto &it : a)
    simula[it]++;
  for (int i = 1; i <= h; i++) {
    int flag = 1;
    for (auto &it : b)
      if (!simula[(i + it) % h]) {
        flag = 0;
        break;
      }
    if (flag) return 1;
  }
  return 0;
}

int main() {
  int n, l;
  cin >> n >> l;
  vi a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  if (solve(a, b, l))
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
