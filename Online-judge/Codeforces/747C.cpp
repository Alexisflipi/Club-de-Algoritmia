#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
const lld MAX = 1e5 + 7;
typedef vector<lld> vi;
typedef pair<lld, vi> par;

bool compu[105];

struct Server{
  lld t;
  lld k;
  lld d;
  bool operator<(const Server &e) const{
    return t < e.t;
  }
}s[MAX];

void solve(lld Q, lld N){
  priority_queue<par> c;
  lld mo = 0;
  lld ml = N;
  vi ans;
  for (lld i = 0; i < Q; i++){
    lld t = s[i].t;
    lld k = s[i].k;
    lld d = s[i].d;
    lld tra = t + d - 1;
    vi g;
    if (c.empty()){
      ans.push_back(k * (k + 1)/2);
      for (lld j = 0; j < k; j++)
        g.push_back(j + 1), compu[j + 1] = true;
      ml -= k;
      c.push(par(-tra, g));
      continue;
    }
    while (!c.empty() && t > -c.top().first){
      for (lld j = 0; j < c.top().second.size(); j++)
        compu[c.top().second[j]] = false;
      ml += c.top().second.size();
      c.pop();
    }
    if (ml >= k){
      lld cont = 0;
      lld r = 0;
      for (lld j = 0; j < 105 && cont < k; j++){
        if (!compu[j + 1]){
          g.push_back(j + 1);
          compu[j + 1] = true;
          r += (j + 1);
          cont++;
        }
      }
      c.push(par(-tra, g));
      ml -= g.size();
      ans.push_back(r);
    }else{
      ans.push_back(-1);
    }
  }
  for (auto it : ans)
    cout << it << "\n";
}

int main(){
  lld n, q;
  cin >> n >> q;
  for (lld i = 0; i < q; i++)
    cin >> s[i].t >> s[i].k >> s[i].d;
  sort(s, s + q);
  solve(q, n);
  return 0;
}
/*
4 3
3 4 3
1 3 2
2 2 1
*/
