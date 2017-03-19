#include <bits/stdc++.h>
using namespace std;

//Lista doblemente enlazada
//inserta elementos 
//-> izq : 0
//-> der : 1

struct node{
  int val;
  node *right, *left;
  node(int n) : val(n), right(NULL), left(NULL) {}
};

node *insertar(node *root, int val, int d) {
  if (root == NULL) return new node(val);
  node *aux = new node(val);

  if (d) {
    node *temp = root -> right;
    root -> right = aux;
    aux -> left = root;
    if (temp != NULL)
      aux -> right = temp, 
      temp -> left = aux;
  } else {
    node *temp = root -> left;
    root -> left = aux;
    aux -> right = root;
    if (temp != NULL)
      aux -> left = temp, 
      temp -> right = aux;
  }
  return root;
}

void imprimir(node *root) {
  if (root == NULL) {
    cout << '\n';
    return;
  }
  cout << root -> val << ' ';
  imprimir(root -> right);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, p;
  cin >> n >> p;
  node *root = NULL;
  //Insertar elementos 
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    root = insertar(root, a, 1);
    if (root -> right != NULL)
      root = root -> right;
  }
  //Mueve al principio de la lista
  while (root -> left != NULL)
    root = root -> left;
  
  //Mueve a la p-esima posicion
  for (int i = 0; i < p - 1; i++)
    if (root -> right != NULL)
      root = root -> right;

  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    string s; cin >> s;
    if (s == "moveLeft") {
      if (root -> left != NULL)
        root = root -> left;
      continue;
    }
    if (s == "moveRight") {
      if (root -> right != NULL)
        root = root -> right;
      continue;
    }
    if (s == "insertLeft") {
      int a; cin >> a;
      root = insertar(root, a, 0);
      continue;
    }
    if (s == "insertRight") {
      int a; cin >> a;
      root = insertar(root, a, 1);
      continue;
    }
    cout << root -> val << "\n";
  }

  return 0;
}
/*
3 2
2 3 5
15
moveLeft
insertLeft 1
moveLeft
print
moveLeft
moveRight
print
moveRight
insertRight 4
moveRight
moveRight
print
moveRight
moveLeft
print
*/
