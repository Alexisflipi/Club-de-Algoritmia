#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
int main() {
  lld N;
  cin >> N;
  lld maxi = -(1 << 30);
  lld sum = 0;
  for (lld i = 0; i < N; i++) {
    lld a; cin >> a;
    maxi = max(maxi, a);
    sum += a;
  }
  cout << N * maxi - sum << "\n";
}
