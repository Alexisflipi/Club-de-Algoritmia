#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

//Binary Search Tree
//Nodos indexados de 0 ... n - 1

//c indica el tipo de dato a guardar
typedef char c;
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
  void traversal(int root, int f) {
    visited = vi(visited.size(), 0);
    t.clear();
    dfs(root, f);
  }
  //Devuelve la existencia de un elemento
  bool buscar(int nodo, c x){
    if (nodo == -1) return 0;
    if (clave[nodo] == x) return 1;
    else return (clave[nodo] < x) ? 
          buscar(der[nodo], x):
          buscar(izq[nodo], x);
  }
};

int main() {
  return 0;
}
