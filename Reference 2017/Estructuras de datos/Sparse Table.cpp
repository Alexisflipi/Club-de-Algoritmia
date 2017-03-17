#include <bits/stdc++.h>

using namespace std;

//Sparse table
//Built : O(n * log n)
//Memory: O(n * log n)
//Query : O(1)
//Not support actualization

typedef long long int lli;
#define MAXN 200003
#define LOGMAXN  20  

lli M[MAXN][LOGMAXN];
lli logTable[MAXN];
lli aux[MAXN];

struct SparseTable {
  int n;
  SparseTable(int t) : n(t) {}

  void add(lli idx, lli a) {
    aux[idx] = a;
  }

  void process(){
    int i, j;
    for(i = 2; i <= n; i++)
      logTable[i] = logTable[i >> 1] + 1;

    for (i = 0; i < n; i++)
      M[i][0] = i;

    for (j = 1; 1 << j <= n; j++)
      for (i = 0; i + (1 << j) - 1 < n; i++)
        if (aux[M[i][j - 1]] <= aux[M[i + (1 << (j - 1))][j - 1]])
          M[i][j] = M[i][j - 1];
        else
          M[i][j] = M[i + (1 << (j - 1))][j - 1];
  }

  lli query(int i, int j){
    if(i > j) return 0;
    int k = logTable[j - i + 1];
    if(aux[M[i][k]] <= aux[M[j - (1<<k) + 1][k]])
      return aux[M[i][k]];
    return aux[M[j - (1<<k) + 1][k]];
  }
};

int main() {
  return 0;
}
