#include <bits/stdc++.h>
  using namespace std;

  typedef vector<int> vi;
  typedef pair<int, int> ii;

  struct Bipartito {
    int n; vi p;
    vector<vi> egde;
    vector<bool> set, visit;

    Bipartito(int N) : set(N), p(N),
        visit(N), egde(N), n(N) {}

    void AgregarArista(int u, int v) {
      egde[u].push_back(v);
      egde[v].push_back(u);
    }

    void AgregarIzq(int u) { set[u] = true; }
    void AgregarDer(int u) { set[u] = false; }

    int CaminoIncremental(int u) {
      visit[u] = true;
      for (int i = 0; i < egde[u].size(); ++i)
        if (p[egde[u][i]] == -1) 
          return p[egde[u][i]] = u;
      for (int i = 0; i < egde[u].size(); ++i) {
        int v = egde[u][i];
        if (visit[p[v]]) continue;
        if (CaminoIncremental(p[v]) != -1)
          return p[v] = u;
      }
      return -1;
    }

    vector<ii> MaxEmparejamiento() {
      fill(p.begin(), p.end(), -1);
      for (int i = 0; i < n; ++i) {
        if (!set[i]) continue; CaminoIncremental(i);
        fill(visit.begin(), visit.end(), false);
      }
      vector<ii> pares;
      for (int i = 0; i < n; ++i)
        if (!set[i] && p[i] != -1)
          pares.push_back(ii(p[i], i));
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
    vector<ii> ans = B.MaxEmparejamiento();
    cout << ans.size() << "\n";
  }
  /*
  3 4
  1 1
  1 3
  2 2
  3 2
  */
