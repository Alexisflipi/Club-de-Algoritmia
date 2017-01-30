#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct G {
  vector<vi> ady;
  vi num, parent, low, art;
  vii bridge;
  int N;
  G(int n) : N(n), num(n, -1), ady(n, vi()), 
  parent(n), low(n), art(n) {}

  void add(int a, int b) {
    ady[a].push_back(b);
    //ady[b].push_back(a);
  }

  int root, rootChildren, NC;
  void apb(int u) {
    low[u] = num[u] = NC++;
    for (auto v : ady[u]) {
      if (num[v] == -1) {
        parent[v] = u;
        if (u == root) rootChildren++; apb(v);
        // for articulation point
        if (low[v] >= num[u]) art[u] = 1; 
        if (low[v] > num[u]) // for bridge
          bridge.push_back(ii(min(u, v), max(u, v)));
        low[u] = min(low[u], low[v]);
      } else 
        if (v != parent[u])
          low[u] = min(low[u], num[v]);
    }
  }
  vii artpoint() {
    root = 0;
    NC = 0;
    for (int i = 0; i < N; i++)
      if (num[i] == -1) {
        root = i, rootChildren = 0, apb(i);
        art[root] = (rootChildren > 1);
      }
    return bridge;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  while (cin >> n) {
    cin.ignore();
    G graph(n);
    for (int i = 0; i < n; i++) {
      int num, a; string s;
      cin >> num >> s;
      s.erase(0, 1); s.erase(s.size() - 1, 1);
      int tam = atoi(s.c_str());
      for (int i = 0; i < tam; i++)
        cin >> a, graph.add(num, a);
    }
    vii ans = graph.artpoint();
    sort(ans.begin(), ans.end());
    cout << ans.size() << " critical links\n";
    for (auto &c : ans)
      cout << c.fst << " - " << c.snd << "\n";
    cout << "\n";
  }
  return 0;
}
/*
8
0 (1) 1
1 (3) 2 0 3
2 (2) 1 3
3 (3) 1 2 4
4 (1) 3
7 (1) 6
6 (1) 7
5 (0)
0
*/
