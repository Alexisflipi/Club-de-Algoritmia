#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vi;
const int INF (1<<25);
const int A = 40;
struct G{
  int n;
  int cont;
  vector<vi> m;
  vector<vector<int> > p;
  vector<int> u;

  G(int N) : n(N), m(N, vi(N, ii(INF, -1))), p(N, vector<int>(N, 0)) {}

  void conect(int a, int b, int costo, int r){
    if (m[a][b].second != -1)
      m[a][b] = ii(costo, 2);
    else
      m[a][b] = ii(costo, r);
  }

  void Floyd_W(){
    for (int k = 0; k < n; k++)
      m[k][k].first = 0; //si no es multigrafo
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        p[i][j] = i;
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if (m[i][k].first + m[k][j].first < m[i][j].first){
            m[i][j].first = m[i][k].first + m[k][j].first;
            p[i][j] = p[k][j];
          }
  }
  void path(int i, int j){
    if (i != j) path(i, p[i][j]);
    u.push_back(j);
  }
  int query(int a, int b, int c){
    u.clear();
    path(a, b);
    for (int i = 0; i < u.size() - 1; i++){
      if (m[u[i]][u[i + 1]].second == 2) continue;
      if (m[u[i]][u[i + 1]].second != c)
        return INF;
    }
    return m[a][b].first;
  }
  int f(int s1, int s2){
    int mini = INF;
    for (int k = 0; k < n; k++){
      int x = query(s1, k, 1);
      int y = query(s2, k, 0);
      if (x != INF && y != INF){
        mini = min(mini, x + y);
      }
    }
    return mini;
  }
  pair<int, vector<int> > search(int s1, int s2){
    int mini = f(s1, s2);
    vector<int> ans;
    if (mini == INF) return make_pair(-1, ans);
    for (int k = 0; k < n; k++){
      int x = query(s1, k, 1);
      int y = query(s2, k, 0);
      if (x != INF && y != INF)
        if (x + y == mini) ans.push_back(k);
    }
    sort(ans.begin(), ans.end());
    return make_pair(mini, ans);
  }
};

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  while (cin >> n and n){
    G graph(A);
    for (int i = 0; i < n; i++){
      char age, bi, a, b; int cost;
      cin >> age >> bi >> a >> b >> cost;
      if (bi == 'B'){
        graph.conect(a - 'A', b - 'A', cost, ((age == 'Y') ? 1 : 0));
        graph.conect(b - 'A', a - 'A', cost, ((age == 'Y') ? 1 : 0));
      }else
        graph.conect(a - 'A', b - 'A', cost, ((age == 'Y') ? 1 : 0));
    }
    char s1, s2;
    cin >> s1 >> s2;
    graph.Floyd_W();
    pair<int, vector<int> > r = graph.search(s1 - 'A', s2 - 'A');
    if (r.first == -1)
      cout << "You will never meet.\n";
    else{
      cout << r.first << " ";
      for (int i = 0; i < r.second.size() - 1; i++)
        cout << char(r.second[i] + 'A') << " ";
      cout << char(r.second[r.second.size() - 1] + 'A') << "\n";
    }
  }
  return 0;
}
/*
4
Y U A B 4
Y U C A 1
M U D B 6
M B C D 2
A D
2
Y U A B 10
M U C D 20
A D
0
*/
