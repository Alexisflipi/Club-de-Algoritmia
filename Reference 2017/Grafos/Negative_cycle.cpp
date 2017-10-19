 vector<Costo> dist; // <- Resultado

bool BellmanFerrari(int s) {
  queue<int> q; 
  vector<bool> en_cola(n);
  vector<int> procesado(n);
  dist = vector<Costo>(n, INF);
  q.push(s), dist[s] = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop(), en_cola[u] = false;
    if (++procesado[u] == n) return true;
    for (CostoNodo arista : ady[u]) {
      int v = arista.second;
      Costo p = arista.first;
      if (dist[u] + p < dist[v]) {
        if (!en_cola[v]) q.push(v);
        dist[v] = dist[u] + p;
        en_cola[v] = true;
      }
    }
  }
  return false;
}

bool BellmanFord(int s) {
  //v number of vertices
  vi dist(v, oo); dist[s] = 0;
  bool hasNegaCycle = 0;
  for (int i = 0; i < v; i++) {
    bool modi = 0;
    for (int u = 0; u < v; u++) {
      for (auto &v : ady[u]) {
        if (dist[u] + v.second < dist[v.first]) {
          dist[v.first] = dist[u] + v.second;
          modi = 1;
        }
      }
    }
    if (!modi) break;
    if (modi && i == v - 1) hasNegaCycle = 1;
  }
  return hasNegaCycle;
}

