#include <bits/stdc++.h>
using namespace std;

const int INF = (1<<30);
typedef string st;
typedef pair<st, st> ii;
typedef vector<ii> vss;
typedef vector<st> vs;

struct G{
  int n;
  vector<vector<int> > ady;
  map<st, int> ida;
  map<int, st> reg;
  G(int N, vs d) : ady(N), n(N) { 
    for (int i = 0; i < N; i++) 
      reg[i] = d[i], ida[d[i]] = i;
  }

  void connect(st a, st b) {
    ady[ida[a]].push_back(ida[b]);
    ady[ida[b]].push_back(ida[a]);
  }

  int bfs(st source, st sink) {
    vector<int> dist(n, INF);
    queue<int> Q;
    Q.push(ida[source]);
    dist[ida[source]] = 0;
    while (!Q.empty()) {
      int u = Q.front(); Q.pop();
      for (auto v : ady[u])
        if (dist[v] == INF)
          dist[v] = dist[u] + 1, Q.push(v);
    }
    return dist[ida[sink]];
  }
};


vss read(st s) {
  vss a;
  while (1){
    getline(cin, s);
    if (s.empty()) break;
    stringstream ss(s);
    st g;
    vs aux;
    while (ss >> g)
      aux.push_back(g);
    a.push_back(ii(aux[0], aux[1]));
  }
  return a;
}

G build(vs a) {
  int m = a.size();
  G graph(m, a);
  sort(a.begin(), a.end());
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      if (a[i].size() != a[j].size()) continue;
      int cont = 0;
      for (int k = 0; k < a[i].size(); k++)
        if (a[i][k] != a[j][k]) cont++;
      if (cont == 1)
        graph.connect(a[i], a[j]);
    }
  }
  return graph;
}

int main() {
  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    if (i > 0) cout << "\n";
    st s = ".";
    vs sub;
    while (s != "*")
      cin >> s, sub.push_back(s);
    cin.ignore();
    vss s_t = read(s);
    G graph = build(sub);
    for (auto q : s_t) {
      cout << q.first << " " << q.second << " ";
      cout << graph.bfs(q.first, q.second) << "\n";
    }
  }
  return 0;
}
/*
1
dip
lip
mad
map
maple
may
pad
pip
pod
pop
sap
sip
slice
slick
spice
stick
stock
*
spice stock
may pod
*/
