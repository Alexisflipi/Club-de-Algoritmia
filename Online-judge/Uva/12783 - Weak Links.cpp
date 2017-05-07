#include <bits/stdc++.h>
#define forn(i, a, b) for (int i = a; i < b; i++)
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

  void connect(int a, int b) {
    ady[a].push_back(b);
    ady[b].push_back(a);
  }

  int root, rootChildren, NC;
  void apb(int u) {
    low[u] = num[u] = NC++;
    for (auto v : ady[u]) {
      if (num[v] == -1) {
        parent[v] = u;
        if (u == root) rootChildren++; apb(v);
        if (low[v] >= num[u]) art[u] = 1; 
        if (low[v] > num[u])
          bridge.push_back(ii(min(u, v), max(u, v)));
        low[u] = min(low[u], low[v]);
      } else if (v != parent[u])
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
  int v, e;
  while (cin >> v >> e and v and e) {
    G *graph = new G(v);
    forn(i, 0, e) {
      int a, b; cin >> a >> b;
      graph -> connect(a, b);
    }
    vii bridge = graph -> artpoint();
    sort(bridge.begin(), bridge.end());
    cout << bridge.size();
    forn(i, 0, bridge.size())
      cout << " " << bridge[i].first << " " << bridge[i].second;
    
    cout << '\n';
  }
  return 0;
}
/*
4 3
0 3
0 1
0 2
7 8
0 1
0 2
1 3
2 3
3 4
4 5
4 6
5 6
0 0
*/
