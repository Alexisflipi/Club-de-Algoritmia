#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int N, Q;
  cin >> N >> Q;
  vi t(N + 1, 0);
  for (int i = 0; i < N; i++)
    cin >> t[i + 1];
  for (int i = 1; i <= N; i++)
    t[i] += t[i - 1];

  for (int i = 0; i < Q; i++){
    int query;
    cin >> query;
    for (int j = 0; j < N; j++){
      if (query >= t[j] && query < t[j + 1]){
        cout << j + 1 << '\n';
        break;
      }
    }
  }
  return 0;
}
