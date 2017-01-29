#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef long long lld;
typedef pair<lld, lld> ii;
typedef vector<lld> vi;
typedef vector<ii> vii;
typedef vector<pair<lld, ii>> viii;
const lld INF (1<<30);

struct UnionFind{
  lld n, sets;
  vi p, r, s;
  UnionFind(lld N) : n(N), sets(N), 
  r(N), s(N, 1), p(N) { 
    while (--N) p[N] = N; 
  }
  //Find, utiliza compresión de caminos
  lld Find(lld i) {
    return (i == p[i]) ? i : (p[i] = Find(p[i]));
  }
  //Determina si están en la misma componente
  bool isSameSet(lld i, lld j) {
    return (Find(i) == Find(j));
  }
  //Union, utiliza rango para un arbol corto y sea O(~1)
  void Union(lld i, lld j) {
    lld x = Find(i), y = Find(j);
    if (x == y) return; else sets--;
    (r[x] > r[y]) ? p[y] = x, s[y] += s[x] 
                  : p[x] = y, s[x] += s[y];
    if (r[x] == r[y]) r[y]++;
  }
  //Retorna el tamaño del conjunto del nodo i
  lld sizeSet(lld i) {
    return s[Find(i)];
  }
  //Retorna el número de componentes conexas
  lld numSet() {
    return sets;
  }
};

//Árbol de expansión mínima
//Algortimo kruskal
//Time complexity: O(E*logV)
//Retorna las aristas que pertenecen al MST
struct K{
  lld n;
  viii edges;
  K(lld N) : n(N) {}
  
  void connect(lld a, lld b, lld cost) {
    edges.push_back(make_pair(cost, ii(a, b)));
  }

  lld kruskal(lld idx) {
    UnionFind UF(n);
    vii MST; //Contiene las aristas del MST
    sort(edges.begin(), edges.end());
    lld mx = -INF;
    for (lld i = idx; i < edges.size(); i++) {
      lld w = edges[i].fst;
      lld a = edges[i].snd.fst;
      lld b = edges[i].snd.snd;
      if (!UF.isSameSet(a, b)) {
        MST.push_back(edges[i].snd);
        mx = max(mx, w);
        UF.Union(a, b);
      }
    }
    //Existencia de MST:
    return (UF.numSet() != 1) ? -1 : mx; // costo del MST
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  lld v, e;
  while (cin >> v >> e) {
    if (v == 0 && e == 0) break;
    K kl(v);
    for (lld i = 0; i < e; i++) {
      lld a, b, w;
      cin >> a >> b >> w;
      kl.connect(--a, --b, w);
    }
    lld mn = INF;
    for (lld i = 0; i < e; i++) {
      lld r = kl.kruskal(i);
      if (r != -1)
        mn = min(mn, r - kl.edges[i].fst);
    }
    (mn == INF) ? cout << "-1\n" : cout << mn << "\n";
  }
  return 0;
}
