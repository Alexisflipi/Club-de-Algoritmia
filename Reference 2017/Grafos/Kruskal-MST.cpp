#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> viii;

//Árbol de expansión mínima
//Algortimo kruskal
//Time complexity: O(E*logV)
//Retorna las aristas que pertenecen al MST
struct K{
  int n;
  viii edges;
  K(int N) : n(N) {}
  
  void connect(int a, int b, int cost) {
    edges.push_back(make_pair(cost, ii(a, b)));
  }

  int kruskal() {
    UnionFind UF(n);
    vii MST; //Contiene las aristas del MST
    sort(edges.begin(), edges.end());
    int cost = 0;
    for (auto &e : edges) {
      int w = e.fst;
      int a = e.snd.fst;
      int b = e.snd.snd;
      if (!UF.isSameSet(a, b)) {
        MST.push_back(e.snd);
        cost += w;
        UF.Union(a, b);
      }
    }
    //Existencia de MST:
    return (UF.numSet() != 1) ? -1 : cost; // costo del MST
  }
};
