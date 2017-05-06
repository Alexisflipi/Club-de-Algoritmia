#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 7;
double a[MAX];
double b[MAX];

int main() {
  double p;
  int n;
  cin >> n >> p;
  double sum = 0;
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i], sum += a[i];
  if (sum <= p)
    cout << "-1\n";
  else {
    double lo = 0.0, hi = 1e10;
    for (int i = 0; i < 60; i++) {
      double mid = (lo + hi) / 2.0;
      double c = 0.0;
      for (int i = 0; i < n; i++)
        c += max(0.0, a[i] - b[i]/mid);
      if (c <= p) lo = mid;
      else hi = mid;
    }
    cout << fixed << setprecision(6);
    cout << lo << '\n';
  }
  return 0;
}
