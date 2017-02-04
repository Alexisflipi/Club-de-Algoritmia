#include <bits/stdc++.h>
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
    ady[b].push_back(a);
  }

  int root, rootChildren, NC;
  void apb(int u) {
    low[u] = num[u] = NC++;
    for (auto v : ady[u]) {
      if (num[v] == -1) {
        parent[v] = u;
        if (u == root) rootChildren++; apb(v);
        if (low[v] >= num[u]) art[u]++; 
        low[u] = min(low[u], low[v]);
      } else  if (v != parent[u])
          low[u] = min(low[u], num[v]);
    }
  }
  vi artpoint() {
    root = 0;
    NC = 0;
    for (int i = 0; i < N; i++)
      if (num[i] == -1) {
        root = i, rootChildren = 0, apb(i);
        art[i] = (rootChildren > 1);
      }
    return art;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  int a, b;
  while (cin >> n >> m) {
    G graph(n);
    if (!n and !m) break;
    while (cin >> a >> b) {
      if (a == -1) break;
      graph.add(a, b);
    }
    vi art = graph.artpoint();
    vii ans;
    for (int i = 0; i < art.size(); i++)
      ans.push_back(ii(-(art[i] + 1), i));
    sort(ans.begin(), ans.end());
    int cont = 0;
    for (auto &it : ans)
      if (cont++ == m) break;
      else cout << it.second << " " << -it.first << "\n";
    cout << "\n";
  }
  return 0;
}
/*
8 4
0 4
1 2
2 3
2 4
3 5
3 6
3 7
6 7
-1 -1
0 0
*/
