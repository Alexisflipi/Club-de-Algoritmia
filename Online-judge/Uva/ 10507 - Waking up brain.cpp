#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const int A = 30;

int ady(int u, vector<vi> &g, map<int, int> &m){
  for (auto v : g[u])
    m[v]++;
}

int check(vector<bool> f){
  int cont = 0;
  for (auto it : f)
    if (it) cont++;
  return cont;
}

int solve(vector<vi> &g, string s, int n){
  vector<bool> vis(A);
  map<int, int> m;
  for (auto it : s)
    m[it - 'A'] = 3, ady(it - 'A', g, m), vis[it - 'A'] = true;
  int years = 0;
  while (check(vis) < n){
    bool flag = false;
    map<int, int> aux = m;
    for (auto it : aux){
      if (vis[it.first]) continue;
      if (it.second >= 3){
        ady(it.first, g, m), vis[it.first] = true, flag = true;
      }
    }
    if (!flag) return -1;
    years++;
  }
  return years;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  while (cin >> n){
    cin >> m;
    string s; cin >> s;
    vector<vi> graph(A);
    for (int i = 0; i < m; i++){
      string g; cin >> g;
      int a = g[0] - 'A';
      int b = g[1] - 'A';
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    int r = solve(graph, s, n);
    if (r != -1) 
         cout << "WAKE UP IN, " << r << ", YEARS\n";
    else cout << "THIS BRAIN NEVER WAKES UP\n";
  }
  return 0;
}
/*
6
11
HAB
AB
AC
AH
BD
BC
BF
CD
CF
CH
DF
FH
*/
