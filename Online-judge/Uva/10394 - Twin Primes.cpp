#include <bits/stdc++.h>
#define forn(i, a, b) for (int i = a; i < b; i++)
#define fst first
#define snd second
#define pb(a) push_back(a)
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int MAX = 2 * 1e7 + 1;

bool m[MAX];
vi primes;

void criba() {
  for (int i = 3; i < MAX; i += 2) m[i] = 1;
  m[2] = 1;
  primes.pb(2);
  for (int i = 3; i * i < MAX; i += 2)
    if (m[i]) for (int j = i * i; j < MAX; j += i) m[j] = 0;
  for (int i = 3; i < MAX; i += 2)
    if (m[i]) primes.push_back(i);
}

vii twin;

void pre() {
  for (auto &p : primes)
    if (m[p + 2])
      twin.push_back(ii(p, p + 2));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  criba();
  pre();
  int n;
  while (cin >> n) {
    cout << "(" << twin[n - 1].fst << ", " << twin[n - 1].snd << ")" << '\n';
  }
  return 0;
}
