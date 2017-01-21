#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
const lld A = 1000;
bool f[A * A + 5];
void criba() {
  for (lld i = 3; i < A * A + 3; i += 2) 
    f[i] = true;
  f[2] = true;
  for (lld i = 3; i * i < A * A + 3; i += 2) 
    if (f[i])
      for (lld j = i * i; j < A * A + 3; j += i) f[j] = false;
}

bool isprime(lld n) {
  return f[n];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  criba();
  lld N; cin >> N;
  for (lld m = 1; m <= A; m++) 
    if (!isprime(N * m + 1)) {
      cout << m << "\n";
      break;
    }
  return 0;
}
