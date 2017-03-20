#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

//Binary Search Tree
//Nodos indexados de 0 ... n - 1

//c indica el tipo de dato a guardar
typedef int c;
typedef vector<int> vi;

struct T{
  vector<c> clave;
  vi izq, der, visited;
  vector<c> t;
  int nodos = 0;

  T(int n) : izq(n), der(n), visited(n), clave(n) {}

  //Si u es raiz, entonces raiz = crear_nodo(u)
  int crear_nodo(c dato){
    clave[nodos] = dato;
    izq[nodos] = -1;
    der[nodos] = -1;
    return nodos++;
  }
  //Si se requiere insertar un nuevo elemento
  void insertar(int nodo, c dato){
    if (clave[nodo] > dato)
      if (izq[nodo] == -1) 
        izq[nodo] = crear_nodo(dato);
      else insertar(izq[nodo], dato);
    else
      if (der[nodo] == -1) 
        der[nodo] = crear_nodo(dato);
      else insertar(der[nodo], dato);
  }
  void dfs(int nodo, int f){
    if (nodo == -1) return;
    if (f == 1) visited[nodo] = 1, 
      t.push_back(clave[nodo]);
    dfs(izq[nodo], f);
    if (f == 2) visited[nodo] = 1, 
      t.push_back(clave[nodo]);
    dfs(der[nodo], f);
    if (f == 3) visited[nodo] = 1, 
      t.push_back(clave[nodo]);
  }
  //pre-orden: f = 1
  //in-orden: f = 2
  //post-orden: f = 3
  vi traversal(int root, int f) {
    visited = vi(visited.size(), 0);
    t.clear();
    dfs(root, f);
    return t;
  }
};

void print(vi aux) {
  for (auto &it : aux)
    cout << ' ' << it;
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  for (int i = 0; i < t; i++) {
    int n; cin >> n;
    T *bst = new T(n);
    int root; cin >> root;
    bst -> crear_nodo(root);
    for (int j = 1; j < n; j++) {
      int a; cin >> a;
      bst -> insertar(0, a);
    }
    cout << "Case " << i + 1 << ":\n";
    cout << "Pre.:";
    print((bst -> traversal(0, 1)));
    cout << "In..:";
    print(bst -> traversal(0, 2));
    cout << "Post:";
    print(bst -> traversal(0, 3));
    cout << '\n';
  }
  return 0;
}
/*
2
3
5 2 7
9
8 3 10 14 6 4 13 7 1
*/
