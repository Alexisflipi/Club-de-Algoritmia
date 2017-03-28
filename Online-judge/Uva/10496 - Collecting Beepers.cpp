#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

const int MAX = 21;
const int INF = (1<<30);

int b;
int dist[MAX][2000];
int memo[MAX][2000];

int tsp(int idx, int mask) {
  if (mask == (1<<b) - 1)
    return dist[idx][0];
  if (memo[idx][mask] != -1) return memo[idx][mask];
  int ans = INF;
  for (int i = 0; i < b; i++) {
    if (mask & (1<<i) || idx == i) continue;
    ans = min(ans, dist[idx][i] + tsp(i, mask|(1<<i)));
  }
  return memo[idx][mask] = ans;
}

int d(ii a, ii b, int i, int j) {
  return abs(b.fst - a.fst) + abs(b.snd - a.snd);
}

int main() {
  int t; cin >> t;
  while (t--) {
    int n, m; 
    cin >> n >> m;
    int x, y; cin >> x >> y;
    vii coor;
    coor.push_back(ii(x, y));
    cin >> b;
    for (int i = 0; i < b; i++) {
      cin >> x >> y;
      coor.push_back(ii(x, y));
    }
    b++;
    for (int i = 0; i < coor.size(); i++)
      for (int j = 0; j < coor.size(); j++)
        dist[i][j] = d(coor[i], coor[j], i, j);
      
    memset(memo, -1, sizeof memo);
    cout << "The shortest path has length ";
    cout << tsp(0, 1) << '\n';
    coor.clear();
    memset(dist, 0, sizeof dist);
  }
  return 0;
}
/*
1
10 10
1 1
4
2 3
5 5
9 4
6 5
*/
