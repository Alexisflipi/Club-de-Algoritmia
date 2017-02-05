#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

struct UnionFind{
  int n, sets;
  vi p, r, s, sum;
  UnionFind(int N) : n(2 * (N + 10)), sets(n), 
  r(n), s(n), p(n), sum(n) { 
    for (int i = 1, j = N + 1; i <= N; i++, j++)
      p[i] = j, p[j] = j, sum[j] = i, s[j] = 1;
  }
  //Find, utiliza compresión de caminos
  int Find(int i) {
    return (i == p[i]) ? i : (p[i] = Find(p[i]));
  }
  //Determina si están en la misma componente
  bool isSameSet(int i, int j) {
    return (Find(i) == Find(j));
  }
  //Union, utiliza rango para un arbol corto y sea O(~1)
  void Union(int i, int j) {
    int x = Find(i), y = Find(j);
    if (x == y) return;
    s[y] += s[x];
    sum[y] += sum[x];
    p[x] = y;
  }
  //Retorna el tamaño del conjunto del nodo i
  void Disjoin(int i, int j) {
    int x = Find(i), y = Find(j);
    if (x == y) return;
    ++s[y]; --s[x];
    sum[y] += i; sum[x] -= i;
    p[i] = y;
  }

  ii sizeSet(int i) {
    int r = Find(i);
    return ii(s[r], sum[r]);
  }
  //Retorna el número de componentes conexas
  int numSet() {
    return sets;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  int a, b;
  while (cin >> n >> m) {
    UnionFind UF(n);
    for (int i = 0; i < m; i++) {
      int q; cin >> q;
      if (q == 1) {
        cin >> a >> b;
        UF.Union(a, b);
        continue;
      }
      if (q == 2) {
        cin >> a >> b;
        UF.Disjoin(a, b);
        continue;
      }
      cin >> a;
      ii ans = UF.sizeSet(a);
      cout << ans.fst << " " << ans.snd << '\n';
    }
  }
  return 0;
}
/*
5  7
1  1  2
2  3  4
1  3  5
3  4
2  4  1
3  4
3  3
*/
