#include <bits/stdc++.h>
using namespace std;

int main(){
  int T; cin >> T;
  cin.ignore();
  string s;
  getline(cin, s);
  for (int i = 0; i < T; i++){
    map<string, int> m;
    int cont = 0;
    while (1){
      getline(cin, s);
      if (s.empty()) break;
      cont++;
      m[s]++;
    }
    cout << fixed << setprecision(4);
    if (i > 0) cout << "\n";
    for (auto it : m)
      cout << it.first << " " << double(it.second)/double(cont)*100.0 << "\n";
  }
  return 0;
}
/*
1
Red Alder
Ash
Aspen
Basswood
Ash
Beech
Yellow Birch
Ash
Cherry
Cottonwood
Ash
Cypress
Red Elm
Gum
Hackberry
White Oak
Hickory
Pecan
Hard Maple
White Oak
Soft Maple
Red Oak
Red Oak
White Oak
Poplan
Sassafras
Sycamore
Black Walnut
Willow
*/
