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

//Hash with updated (Fenwick Tree)

const lli M = 104398831ll;
const lli P = 15485863ll;

struct FenTree{
  vi tree;
  lli MOD, B, N;
  FenTree(lli n, lli m, lli b) : 
  tree(n + 1), MOD(m), B(b), N(n) {}

  void Act(lli i, lli v) {
    while (i < tree.size())
      tree[i] = (tree[i] + v) % MOD,
      i += (i & -i);
  }

  lli Query(lli i) {
    lli sum = 0;
    while (i > 0)
      sum = (sum + tree[i]) % MOD,
      i -= (i & - i);
    return sum;
  }
  lli Range(lli i, lli j) {
    lli a = (Query(j) - Query(i - 1) + MOD) % MOD;
    lli r = power(B, N - j, MOD);
    lli b = power(r, MOD - 2, MOD);
    return (a * b) % MOD;
  }
};

int main() {
  FenTree hash1(n, M, P);
  forn(i, 1, n + 1) {
      lli v = data[i - 1];
      lli r = power(P, n - i, M);
      lli q = hash1.Range(i, i);
      hash1.Act(i, ((v - q + M) % M * r % M) % M);
  }
  cin >> l >> r;
  lli f1 = hash1.Range(l, r);
}


