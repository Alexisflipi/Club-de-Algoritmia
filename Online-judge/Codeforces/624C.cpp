#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<string> ans;
struct graph{
  int N;
  vector<vi> ady;
  vector<bool> visited;
  graph(int n) : N(n), ady(n + 1), visited(n + 1) {}

  void add(int a, int b){
    ady[a].push_back(b);
    ady[b].push_back(a);
  }

  void dfsp(int u, string s){
    visited[u] = true;
    if (s.size() == N){
      ans.push_back(s);
      return;
    }
    if (s.empty())
      for (int i = 0; i < 3; i++)
        dfsp(u, s + char(i + 'a'));
    for (auto v : ady[u]){
      if (!visited[v])
        if (s[s.size() - 1] == 'a')
          dfsp(v, s + "a"), dfsp(v, s + "b");
        else
          if (s[s.size() - 1] == 'b')
            dfsp(v, s + "b"), dfsp(v, s + "c");
          else
            dfsp(v, s + "c");
    }
  }
};


int main(){
  int n, m;
  cin >> n >> m;
  graph g(n);
  for (int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g.add(a, b);
  }
  g.dfsp(1, "");
  if (ans.empty()){
    cout << "No\n";
  }else{
    cout << "Yes\n";
    cout << ans[0] << "\n";
  }
  return 0;
}
