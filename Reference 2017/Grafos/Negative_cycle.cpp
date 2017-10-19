
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

