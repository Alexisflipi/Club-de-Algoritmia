#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef vector<lld> vi;

// Fenwick Tree. Indices de 1 a n. 
// Fuente: club de algoritmia ESCOM
// Autor: Ethan Jiménez
struct FenTree{
  vector<lld> tree;
  FenTree(lld n) : tree(n + 1) {}

  void Act(lld i, lld v) {
    while (i < tree.size()) {
      tree[i] += v;
      i += (i & -i);
    }
  }

  lld Query(lld i) {
    lld sum = 0;
    while (i > 0){
      sum += tree[i];
      i -= (i & -i);
    }
    return sum;
  }
  int Rango(int i, int j) {
    return Query(j) - Query(i - 1);
  }
};
//mapeo para números muy grandes y arreglo pequeño
vi m(vi &A){
  vi B = A;
  sort(B.begin(), B.end());
  map<lld, lld> mapeo;
  for (lld i = 0; i < B.size(); i++)
    mapeo[B[i]] = i;
  vi r;
  for (auto it : A)
    r.push_back(mapeo[it] + 1);
  return r;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  lld N;
  vi num;
  for (lld i = 0; i < N; i++) {
    lld a; cin >> a; num.push_back(a);
  }
  vi mapeo = m(num);
  //Contar mínimas inversiones o swap al ordenar un arreglo O(n*log n)
  lld inv = 0;
  FenTree BIT(N);
  for (lld i = mapeo.size() - 1; i >= 0; i--) {
    lld x = BIT.Query(mapeo[i]);
    inv += x;
    BIT.Act(mapeo[i], 1);
  }
  cout << inv << "\n";
}
