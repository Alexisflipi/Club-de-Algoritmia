vector<int> ciclo;
vector<char> color;

void DetectarCiclo(int u, int p) {
  int retorno = bi? 0: 1;
  color[u] = ciclo.empty()? 'G': 'N';
  for (int v : ady[u]) {
    if (v == p && !retorno++) continue;
    if (ciclo.empty() && color[v] == 'G') {
      color[v] = 'A', ciclo.push_back(v);
      if (u != v) color[u] = 'R',
        ciclo.push_back(u);
    }
    if (color[v] != 'B') continue;

    DetectarCiclo(v, u);
    if (color[u] == 'G' && color[v] == 'R')
      color[u] = 'R', ciclo.push_back(u);
  }
  if (color[u] == 'G') color[u] = 'N';
}

vector<vector<int>> DetectarCiclos() {
  vector<vector<int>> ciclos;
  color = vector<char>(n, 'B');
  for (int u = 0; u < n; ++u) {
    if (color[u] != 'B') continue;
    ciclo.clear(); DetectarCiclo(u, n);
    reverse(ciclo.begin(), ciclo.end());
    if (!ciclo.empty())
      ciclos.push_back(ciclo);
  }
  return ciclos;
}
