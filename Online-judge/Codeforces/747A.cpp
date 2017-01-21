#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int mini = (1<<30);
  int a = 0;
  int b = 0;
  for (int i = 0; i < N; i++){
    int r = i + 1;
    if (N % r == 0){
      int p = r;
      int q = N/r;
      if (abs(p - q) < mini){
        mini = abs(p - q);
        a = p;
        b = q;
      }
    }
  }
  if (a > b) swap(a, b);
  cout << a << " " << b << "\n";
  return 0;
}
