#include <bits/stdc++.h>
using namespace std;

// Taken from http://www.stanford.edu/~liszt90/acm/notebook.html
// Gauss-Jordan elimination with full pivoting.
//
// Uses:
//   (1) solving systems of linear equations (AX=B)
//   (2) inverting matrices (AX=I)
//   (3) computing determinants of square matrices
//
// Running time: O(n^3)
//
// INPUT:    a[][] = an nxn matrix
//           b[][] = an nxm matrix
//
// OUTPUT:   X      = an nxm matrix (stored in b[][])
//           A^{-1} = an nxn matrix (stored in a[][])
//           returns determinant of a[][]
const double EPS = 1e-10;

typedef vector<int> VI;
typedef double T;
typedef vector<T> VT;
typedef vector<VT> VVT;

T GaussJordan(VVT &a, VVT &b) {
  const int n = a.size();
  const int m = b[0].size();
  VI irow(n), icol(n), ipiv(n);
  T det = 1;

  for (int i = 0; i < n; i++) {
    int pj = -1, pk = -1;
    for (int j = 0; j < n; j++) if (!ipiv[j])
      for (int k = 0; k < n; k++) if (!ipiv[k])
  if (pj == -1 || fabs(a[j][k]) > fabs(a[pj][pk])) { pj = j; pk = k; }
    ipiv[pk]++;
    swap(a[pj], a[pk]);
    swap(b[pj], b[pk]);
    if (pj != pk) det *= -1;
    irow[i] = pj;
    icol[i] = pk;

    T c = 1.0 / a[pk][pk];
    det *= a[pk][pk];
    a[pk][pk] = 1.0;
    for (int p = 0; p < n; p++) a[pk][p] *= c;
    for (int p = 0; p < m; p++) b[pk][p] *= c;
    for (int p = 0; p < n; p++) if (p != pk) {
      c = a[p][pk];
      a[p][pk] = 0;
      for (int q = 0; q < n; q++) a[p][q] -= a[pk][q] * c;
      for (int q = 0; q < m; q++) b[p][q] -= b[pk][q] * c;      
    }
  }

  for (int p = n-1; p >= 0; p--) if (irow[p] != icol[p]) {
    for (int k = 0; k < n; k++) swap(a[k][irow[p]], a[k][icol[p]]);
  }

  return det;
}
// End of section taken from Stanford's ACM notebook.

// Eliminacion Gaussiana de matrices.
// Definiciones iniciales para Gauss-Jordan.
typedef vector<double> Vector;
typedef vector<Vector> Matriz;

// Para eliminacion con flotantes.
const double ERROR = 1e-9;
bool EsCero(double a) {
  return fabs(a) < ERROR;
}

// En caso de no permitir el pivoteo (eg. cuando
// requieran sacar una matriz inversa) simplemente
// comenten o borren la seccion <comment>.

void EliminacionGaussiana(Matriz& m) {
  for (int i = 0; i < m.size(); ++i) {
    // <comment>
    int fila_mayor = i;
    for (int j = i + 1; j < m.size(); ++j)
      if (fabs(m[fila_mayor][i]) <
        fabs(m[j][i])) fila_mayor = j;
    swap(m[i], m[fila_mayor]);
    // </comment>

    if (EsCero(m[i][i])) continue;
    for (int j = m[i].size() - 1; j >= i; --j)
      m[i][j] = m[i][j] / m[i][i];
    for (int j = 0; j < m.size(); ++j) {
      if (i == j || EsCero(m[j][i])) continue;
      for (int k = m[j].size() - 1; k >= i; --k)
        m[j][k] = m[j][k] - m[i][k] * m[j][i];
    }
  }
}
