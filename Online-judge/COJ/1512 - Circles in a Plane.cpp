#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); 
  int T;
  cin >> T;
  while (T--) {
    long long N; cin >> N;
    cout << N * (N - 1) + 2 << "\n";
  }
  return 0;
}
