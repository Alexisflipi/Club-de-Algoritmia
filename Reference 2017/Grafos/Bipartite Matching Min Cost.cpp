#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef lld Costo;
typedef vector<lld> Lista;
typedef vector<Costo> Costo1D;
typedef vector<Costo1D> Costo2D;

const double ERROR = 1e-9;
const Costo CINF = 1 << 30;

bool Igual(double a, double b) {
    return fabs(a - b) < ERROR;
}
//Emparejamiento máximo de costo mínimo

struct BipartitoCosto {
  Lista pareja, retorno; vector<bool> visitado;
  lld n, s; Costo1D slack, etiqueta; Costo2D costo;

  // Emparejamiento de costo maximo S =  1
  // Emparejamiento de costo minimo S = -1
  
  BipartitoCosto(lld N, lld S = 1)
    : costo(N, Costo1D(N, S * -CINF)), s(S),
      slack(2 * N), etiqueta(2 * N), pareja(2 * N),
      retorno(2 * N), visitado(2 * N), n(N) {}

  void AgregarArista(lld u, lld v, Costo c) { 
    costo[u][v] = c * s; 
  }

  lld EmparejamientoOptimo() {
    fill(pareja.begin(), pareja.end(), -1);
    fill(etiqueta.begin(), etiqueta.end(), 0);
    for (lld i = 0; i < n; ++i) for (lld j = 0; j < n; ++j)
      etiqueta[i] = max(etiqueta[i], costo[i][j]);
            
    for (lld i = 0; i < n; ++i) {
      for (lld j = 0; j < n; ++j)
          slack[j + n] = etiqueta[i] +
              etiqueta[j + n] - costo[i][j];
      fill(visitado.begin(), visitado.end(), false);
      fill(retorno.begin(), retorno.end(), i);
      visitado[i] = true;
      
      bool emparejado = false;
      for (lld j = 0; !emparejado; ++j) {
        lld t = n; 
        for (; t < 2 * n; ++t) {
          if (visitado[t]) continue;
          if (Igual(slack[t], 0)) break;
        }
        if (t < 2 * n) {
          visitado[t] = true;
          if (pareja[t] == -1) {
            emparejado = true;
            for (lld p; ; t = p) {
              pareja[t] = retorno[t];
              p = pareja[retorno[t]];
              pareja[retorno[t]] = t;
              if (retorno[t] == i) break;
            }
          } else {
            visitado[t = pareja[t]] = true;
            for (lld k = 0; k < n; ++k) {
              Costo new_slack = etiqueta[t] +
                  etiqueta[k + n] - costo[t][k];
              if (!Igual(new_slack, slack[k + n])
                && new_slack < slack[k + n]) {
                slack[k + n] = new_slack;
                retorno[k + n] = t;
              }
            }
          }
        } else {
          Costo d = CINF;
          for (lld k = n; k < 2 * n; ++k)
            if (!Igual(slack[k], 0))
              d = min(d, slack[k]);
          for (lld k = 0; k < n; ++k)
            if (visitado[k]) etiqueta[k] -= d;
          for (lld k = n; k < 2 * n; ++k)
            if (!visitado[k]) slack[k] -= d;
            else etiqueta[k] += d;
        }
      }
    }
    lld min_cost = 0;
    for (lld i = 0; i < n; ++i)
      if (!Igual(costo[i][pareja[i] - n], s * -CINF))
        min_cost += costo[i][pareja[i] - n];

    return min_cost; // Emparejamiento optimo.
  }
};

int main() {
  return 0;
}
