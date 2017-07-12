#include <bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  while (cin >> n and n) {
    vector<int> bin;
    while (n > 0) {
      bin.pb(n % 2);
      n /= 2;
    }
    reverse(bin.begin(), bin.end());
    cout << "The parity of ";
    int cont = 0;
    for (auto &it : bin) {
      cout << it; if(it == 1) cont++;
    }
    cout << " is " << cont << " (mod 2).\n";
  }
  return 0;
}
