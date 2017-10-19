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
