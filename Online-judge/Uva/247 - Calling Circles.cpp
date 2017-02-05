#include <bits/stdc++.h>
using namespace std;

typedef pair<string, string> ss;
typedef pair<int, int> ii;
typedef vector<int> vi;

//Strongly connected components
// O(V + E)
struct G{
  vector<vi> ady;
  vector<vi> cfc;
  vi num, low, s, visit;
  int n, cont, NC;
  G(int N) : n(N), ady(N), cfc(N), 
  num(N, -1), low(N), visit(N) {}

  void connect(int a, int b) {
    ady[a].push_back(b);
  }

  void tarjan(int u) {
    low[u] = num[u] = NC++;
    s.push_back(u); visit[u] = 1;
    for (auto &v : ady[u]) {
      if (num[v] == -1) tarjan(v);
      if (visit[v]) 
        low[u] = min(low[u], low[v]);
    }
    if (low[u] == num[u]) {
      while (1) {
        int v = s.back(); 
        s.pop_back(); visit[v] = 0;
        cfc[cont].push_back(v);
        if (u == v) break;
      } cont++;
    }
  }
  vector<vi> scc() {
    cont = 0, NC = 0;
    for (int i = 0; i < n; i++)
      if (num[i] == -1) tarjan(i);
    return cfc;
  }
};

map<string, int> ida;
map<int, string> reg;

void built(set<string> aux) {
  int cont = 0;
  for (auto &it : aux)
    ida[it] = cont, reg[cont] = it, ++cont;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int v, e;
  int t = 0;
  while (cin >> v >> e) {
    if (!v and !e)
      break;
    else if (t) cout << "\n";
    
    G graph(v);
    ida.clear(); reg.clear();
    set<string> bus;
    vector<ss> edge;
    for (int i = 0; i < e; i++) {
      string a, b; cin >> a >> b;
      bus.insert(a); bus.insert(b);
      edge.push_back(ss(a, b));
    }
    built(bus);

    for (auto &it : edge)
      graph.connect(ida[it.first], ida[it.second]);
    
    vector<vi> ans = graph.scc();
    cout << "Calling circles for data set " << ++t << ":\n";
    for (int i = 0; i < graph.cont; i++) {
      for (int j = 0; j < ans[i].size() - 1; j++)
        cout << reg[ans[i][j]] << ", ";
      cout << reg[ans[i][ans[i].size() - 1]] << "\n";
    }
  }
  return 0;
}
/*
8 9
0 1
1 3
3 2
2 1
3 4
4 5
5 7
7 6
6 4

5 6
Ben Alexander
Alexander Dolly
Dolly Ben
Dolly Benedict
Benedict Dolly
Alexander Aaron
14 34
John Aaron
Aaron Benedict
Betsy John
Betsy Ringo
Ringo Dolly
Benedict Paul
John Betsy
John Aaron
Benedict George
Dolly Ringo
Paul Martha
George Ben
Alexander George
Betsy Ringo
Alexander Stephen
Martha Stephen
Benedict Alexander
Stephen Paul
Betsy Ringo
Quincy Martha
Ben Patrick
Betsy Ringo
Patrick Stephen
Paul Alexander
Patrick Ben
Stephen Quincy
Ringo Betsy
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Quincy Martha
0 0
*/
