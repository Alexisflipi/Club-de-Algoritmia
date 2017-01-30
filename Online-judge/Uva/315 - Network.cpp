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
        // for articulation point
        if (low[v] >= num[u]) art[u] = 1; 
        //if (low[v] > num[u]) // for bridge
          //bridge.push_back(ii(u, v));
        low[u] = min(low[u], low[v]);
      } else 
        if (v != parent[u])
          low[u] = min(low[u], num[v]);
    }
  }
  vi artpoint() {
    root = 0;
    NC = 0;
    for (int i = 0; i < N; i++)
      if (num[i] == -1) {
        root = i, rootChildren = 0, apb(i);
        art[root] = (rootChildren > 1);
      }
    return art;
  }
};

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int V, E;
  while (cin >> V && V) {
    G graph(V);
    cin.ignore();
    while (1) {
      string s, r; getline(cin, s);
      if (s[0] == '0') break;
      stringstream ss(s);
      int node = 0;
      int cont = 0;
      while (ss >> r) {
        int p = atoi(r.c_str());
        if (cont == 0) node = --p;
        else graph.add(node, --p);
        cont++;
      }
    }
    int c = 0;
    vi ans = graph.artpoint();
    for (auto &v : ans)
      if (v) c++;
    cout << c << "\n";
  }
  return 0;
}

/*
5
5  1  2  3  4
0
6
2  1  3
5  4  6  2
0
0
*/
