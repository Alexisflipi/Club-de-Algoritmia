#include <bits/stdc++.h>
using namespace std;

string solve(string & s){
  map<char, int> m;
  m['A'] = 0;
  m['G'] = 0;
  m['C'] = 0;
  m['T'] = 0;
  if (s.size() % 4 != 0) return "===";
  
  int signe = 0;
  for (int i = 0; i < s.size(); i++){
    if (s[i] == '?') signe++;
    else m[s[i]]++;
  }
  int maxi = s.size()/4;
  for (auto it : m)
    if (4 * it.second > s.size()) return "===";
  
  int suma = 0;
  for (auto it : m){
    int r = maxi - it.second;
    m[it.first] = r;
    suma += r;
  }
  if (suma == signe){
    for (int i = 0; i < s.size(); i++){
      if (s[i] == '?'){
        if (m['A'] > 0){
          s[i] = 'A';
          m['A']--;
          continue;
        }
        if (m['G'] > 0){
          s[i] = 'G';
          m['G']--;
          continue;
        }
        if (m['C'] > 0){
          s[i] = 'C';
          m['C']--;
          continue;
        }
        if (m['T'] > 0){
          s[i] = 'T';
          m['T']--;
          continue;
        }
      }
    }
    return s;
  }
  return "===";
}

int main(){
  int n;
  string s;
  cin >> n;
  cin >> s;
  cout << solve(s) << "\n";
  return 0;
}
/*
8
A???????
*/
