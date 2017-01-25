#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF (1<<25);
const int A = 107;

struct G{
  int n;
  vector<vi> m;
  vector<vi > p;
  vi u;
  //Si es transitive closure, cambiar INF por 0 en la matriz m
  G(int N) : n(N), m(N, vi(N, 0)), p(N, vector<int>(N, 0)) {}

  void conect(int a, int b, int costo){
    m[a][b] = costo;
  }

  void transitive_closure(){
    //La matriz se llena con 0 en vez de INF:
    //si u -> v entonces m[u][v] = 1 -> costo
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          m[i][j] |= (m[i][k] & m[k][j]);
    //si u esta directamente conectado con v
    //entonces query(u, v) = 1
  }
  int query(int a, int b){
    return m[a][b];
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  int cases = 0;
  while (cin >> n and n) {
    int idx = 0;
    map<string, int> bus;
    vector<string> R;
    G graph(A);
    for (int i = 0; i < n; i++) {
      int m; cin >> m;
      int pre = idx;
      for (int j = 0; j < m; j++) {
        string s; cin >> s;
        bus[s] = idx++; R.push_back(s);
      }
      for (int j = pre; j < idx - 1; j++)
        graph.conect(j, j + 1, 1);
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
      string x, y; cin >> x >> y;
      graph.conect(bus[x], bus[y], 1);
    }
    graph.transitive_closure();
    vector<ii> ans;
    int cont = 0;
    for (int i = 0; i < idx; i++)
      for (int j = i + 1; j < idx; j++)
        if (graph.query(i, j) == 0 && graph.query(j, i) == 0)
          cont++, ans.push_back(ii(i, j));
        
    if (cont) {
      cout << "Case " << ++cases << ", " << cont << " concurrent events:\n";
      if (ans.size() < 2)
        cout << "(" << R[ans[0].fst] << "," << R[ans[0].snd] << ") \n";
      else {
        cout << "(" << R[ans[0].fst] << "," << R[ans[0].snd] << ") ";
        cout << "(" << R[ans[1].fst] << "," << R[ans[1].snd] << ") \n";
      }
    } else {
      cout << "Case " << ++cases << ", " << "no concurrent events.\n";
    }
  }
}
/*
2
2 e1 e2
2 e3 e4
1
e3 e1
3
3 one two three
2 four five
3 six seven eight
2
one four
five six
1
3 x y zee
0
2
2 alpha beta
1 gamma
1
gamma beta
0
*/
