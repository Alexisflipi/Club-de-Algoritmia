#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef vector<lld> vi;

struct Grafo{
  lld n; bool bi;
  vector<vector<lld>> ady;
  Grafo(lld N, bool B = true)
      : n(N), bi(B), ady(N) {}

  void AgregarArista(lld u, lld v) {
      if (bi) ady[v].push_back(u);
      ady[u].push_back(v);
  }
  vector<lld> ciclo;
  vector<char> color;

  void DetectarCiclo(lld u, lld p) {
    lld retorno = bi? 0: 1;
    color[u] = ciclo.empty()? 'G': 'N';
    for (lld v : ady[u]) {
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

  vector<vector<lld>> DetectarCiclos() {
    vector<vector<lld>> ciclos;
    color = vector<char>(n, 'B');
    for (lld u = 0; u < n; ++u) {
      if (color[u] != 'B') continue;
      ciclo.clear(); DetectarCiclo(u, n);
      reverse(ciclo.begin(), ciclo.end());
      if (!ciclo.empty())
          ciclos.push_back(ciclo);
    }
    return ciclos;
  }
};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  lld N; cin >> N;
  Grafo graph(N , false);
  for (lld i = 0; i < N; i++){
    lld a;
    cin >> a; 
    graph.AgregarArista(i, a - 1);
  }
  vector<vi> ans = graph.DetectarCiclos();
  map<lld, lld> m;
  vi num;
  for (lld i = 0; i < ans.size(); i++){
    if (ans[i].empty()) continue;
    for (auto it : ans[i])
      m[it + 1]++;
    if (ans[i].size() % 2 == 0)
      num.push_back(ans[i].size()/2);
    else
      num.push_back(ans[i].size());
  }
  if (m.size() != N){
    cout << "-1\n";
    return 0;
  }

  lld lcm = 1;
  for (auto it : num){
    lcm = lcm * (it/__gcd(lcm, it));
  }
  cout << lcm << "\n";
  return 0;
}
