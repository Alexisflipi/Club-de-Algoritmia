#include <bits/stdc++.h>
using namespace std;

//Topological sort kahn algoritm
//Ojo: Sólo funciona con DAG
typedef vector<int> vi;
const int MAX = 1000;
vi indegree;
vi ts;
vector<vi> grafo;

void kahn(int N){
  priority_queue<int, vector<int>, greater<int>> Q;
  for (int i = 0; i < N; i++)
    if (indegree[i] == 0) Q.push(i);
  
  while (!Q.empty()){
    int u = Q.top(); Q.pop();
    ts.push_back(u);
    for (auto v : grafo[u]){
      indegree[v]--;
      if (indegree[v] == 0) Q.push(v);
    }
  }
}

//Topological sort with DFS in DAG
vi vis;
void dfs(int u){
  vis[u] = 1;
  for (auto v : grafo[u])
    if (!vis[v]) dfs(v);
  ts.push_back(u);
}

int main(){
  int V, E;
  //Via DFS, O(V + E)
  for (int i = 0; i < V; i++)
    if (!vis[i]) dfs(i);
  reverse(ts.begin(), ts.end());

  //Via Kahn, O(V + E)
  kahn(V);

  for (auto it : ts)
    cout << it << " ";
  cout << "\n";
  return 0;
}
