typedef vector<int> Lista;
typedef pair<int, int> Par;

//Max cardinality bipartite matching
//Nodos indexados 0 ... 2 * V
//lado izquierdo nodos impares
//lado derecho nodos pares

struct Bipartito {
  int n; Lista pareja;
  vector<Lista> aristas;
  vector<bool> lado, visitado;

  Bipartito(int N) : lado(N), pareja(N),
      visitado(N), aristas(N), n(N) {}

  void AgregarArista(int u, int v) {
    aristas[u].push_back(v);
    aristas[v].push_back(u);
  }

  void AgregarIzq(int u) { lado[u] = true; }
  void AgregarDer(int u) { lado[u] = false; }

  int CaminoIncremental(int u) {
    visitado[u] = true;
    for (int i = 0; i < aristas[u].size(); ++i)
      if (pareja[aristas[u][i]] == -1) 
        return pareja[aristas[u][i]] = u;
    for (int i = 0; i < aristas[u].size(); ++i) {
      int v = aristas[u][i];
      if (visitado[pareja[v]]) continue;
      if (CaminoIncremental(pareja[v]) != -1)
        return pareja[v] = u;
    }
    return -1;
  }

  vector<Par> MaxEmparejamiento() {
    fill(pareja.begin(), pareja.end(), -1);
    for (int i = 0; i < n; ++i) {
      if (!lado[i]) continue; CaminoIncremental(i);
      fill(visitado.begin(), visitado.end(), false);
    }
    vector<Par> pares;
    for (int i = 0; i < n; ++i)
      if (!lado[i] && pareja[i] != -1)
        pares.push_back(Par(pareja[i], i));
    return pares; // Cardinalidad = pares.size()
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k; cin >> n >> k;
  Bipartito B(2 * n + 5);
  for (int i = 0; i < k; i++) {
    int x, y; cin >> x >> y;
    int a  = 2 * x - 1;
    int b = 2 * y;
    B.AgregarArista(a - 1, b - 1);
    B.AgregarIzq(a - 1);
    B.AgregarDer(b - 1);
  }
  vector<Par> ans = B.MaxEmparejamiento();
  cout << ans.size() << "\n";
}
/*
3 4
1 1
1 3
2 2
3 2
*/
