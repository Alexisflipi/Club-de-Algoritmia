#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct UnionFind{
  int n, sets;
  vi p, r, s;
  UnionFind(int N) : n(N), sets(N), 
  r(N), s(N, 1), p(N) { 
    while (--N) p[N] = N; 
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
  void Union(lli i, lli j) {
    int x = Find(i), y = Find(j);
    if (x == y) return; else sets--;
    (r[x] > r[y]) ? p[y] = x, s[x] += s[y] 
                  : p[x] = y, s[y] += s[x];
    if (r[x] == r[y]) r[y]++;
  }
  //Retorna el tamaño del conjunto del nodo i
  int sizeSet(int i) {
    return s[Find(i)];
  }
  //Retorna el número de componentes conexas
  int numSet() {
    return sets;
  }
};
