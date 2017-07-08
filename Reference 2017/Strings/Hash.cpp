#include <bits/stdc++.h>
using namespace std;

const int MAX = 105;
const int B = 31;
const int inf = (1<<30);

typedef long long lli;
typedef vector<lli> vi;

struct G{
  int len;
  vi H, p;
  G(int n) : H(MAX), p(MAX), len(n - 1) {}

  lli Hash_S(int in, int fin) {
    if (len == fin) return H[in];
    return H[in] - H[fin + 1] * p[fin - in + 1];
  }

  void built(string s) {
    p[0] = 1;
    for (int i = 1; i < MAX; i++)
      p[i] = p[i - 1] * B;
    H[len] = s[len];
    for (int i = len - 1; i >= 0; i--) {
      H[i] = H[i + 1] * B + s[i];
    }
  }
};
