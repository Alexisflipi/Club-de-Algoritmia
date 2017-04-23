#include <bits/stdc++.h>
#define forn(i, a, b) for (lli i = (a); i < (b); i++)
using namespace std;

typedef long long lli;
const lli MAX = 150005;

typedef vector<lli> vi;

vi ady[MAX];
lli degree[MAX];

struct UnionFind{
  lli n, sets;
  vi p, r, s;
  UnionFind(lli N) : n(N), sets(N), 
  r(N), s(N, 1), p(N) { 
    while (--N) p[N] = N; 
  }
  lli Find(lli i) {
    return (i == p[i]) ? i : (p[i] = Find(p[i]));
  }
  bool isSameSet(lli i, lli j) {
    return (Find(i) == Find(j));
  }
  void Union(lli i, lli j) {
    lli x = Find(i), y = Find(j);
    if (x == y) return; else sets--;
    (r[x] > r[y]) ? p[y] = x, s[x] += s[y] 
                  : p[x] = y, s[y] += s[x];
    if (r[x] == r[y]) r[y]++;
  }
  lli sizeSet(lli i) {
    return s[Find(i)];
  }
  lli numSet() {
    return sets;
  }
};

int main() {
  lli n, m;
  cin >> n >> m;
  UnionFind *UF = new UnionFind(n);
  forn(i, 0, m) {
    lli a, b;
    cin >> a >> b;
    degree[--a]++;
    degree[--b]++;
    UF -> Union(a, b);
  }
  forn(i, 0, n)
    ady[UF -> Find(i)].push_back(i);
  bool flag = 1;
  forn(i, 0, n) {
    lli tam = ady[i].size() - 1;
    for (auto &v : ady[i])
      flag &= (degree[v] == tam);
  }
  cout << ((flag) ? "YES" : "NO") << '\n';
  return 0;
}
