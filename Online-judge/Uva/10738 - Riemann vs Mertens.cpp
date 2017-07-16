#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define forn(i, a, b) for (lli i = a; i < b; i++)
#define fst first
#define snd second
using namespace std;

typedef long long lli;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = (1<<30);
const int MAX = 1001;

vi primes;
bool m[MAX];

void criba() {
  for (int i = 3; i < MAX; i += 2) m[i] = 1;
  for (int i = 3; i * i < MAX; i += 2)
    if (m[i]) for (int j = i * i; j < MAX; j += i) m[j] = 0;
  primes.pb(2);
  for (int i = 3; i < MAX; i += 2)
    if (m[i]) primes.pb(i);
}

int mu[MAX * MAX];
int acu[MAX * MAX];

vii des(int n) {
  int r = n;
  int idx = 0;
  vii ans;
  while (idx < primes.size() &&
    primes[idx] * primes[idx] <= n) {
    int p = primes[idx++];
    if (r % p == 0) {
      int e = 0;
      while (r % p == 0) e++, r /= p;
      ans.push_back(ii(p, e));
      if (e > 1) {
        ans.clear();
        return ans;
      }
    }
  }
  if (r > 1) ans.push_back(ii(r, 1));
  return ans;
}

void pre() {
  mu[1] = 1;
  forn(i, 2, MAX * MAX) {
    vii aux = des(i);
    bool flag = 1;
    if (aux.empty()) mu[i] = 0, flag = 0;
    if (flag)
      if (aux.size() % 2 == 0) mu[i] = 1;
      else mu[i] = -1;
  }
  forn(i, 1, MAX * MAX) {
    acu[i] = acu[i - 1] + mu[i];
  }
}

string print(int n) {
  stringstream ss;
  ss << n;
  string r; ss >> r;
  string aux = "";
  for (int i = 0; i < 8 - r.size(); i++)
    aux += " ";
  return aux + r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  criba();
  pre();
  while (cin >> n and n) {
    cout << print(n);
    cout << print(mu[n]);
    cout << print(acu[n]) << '\n';
  }
  return 0;
}
