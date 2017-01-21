#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vi;

vi read(int h) {
  vi g(h);
  for (int i = 0; i < h; i++) 
    cin >> g[i];
  return g;
}

vi solve(vi a, vi b) {
  vi u;
  map<string, int> unir;
  for (auto it : a)
    unir[it]++;
  for (auto it : b)
    unir[it]++;
  for (auto it : unir) {
    if (it.second > 1) 
      u.push_back(it.first);
  }
  return u;
}

vi inter(vi num, vi r){
  vi aux;
  set<string> t;
  for (auto it : r)
    t.insert(it);
  for (auto it : num) {
    if (t.find(it) == t.end()) 
      aux.push_back(it);
  }
  return aux;
}

int main() {
  int n, m; 
  cin >> n >> m;
  vi a = read(n);
  vi b = read(m);
  vi u = solve(a, b);
  a = inter(a, u);
  b = inter(b, u);
  if (u.size() % 2 == 0) {
    int cont = 0;
    if (a.size() > b.size()) 
      cout << "YES\n";
    else
      cout << "NO\n";
  } else {
    int cont = 1;
    if (a.size() + cont > b.size()) 
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
