#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
const lld MOD = 1e9 + 7;
const int MAX = 1000;
int memo[MAX][MAX];

typedef vector<int> vi;


//Calculo de coeficientes binomiales
//Complejidad: O(n*k)
//Memoria: (n^2)
int bino(int n, int k){
  if (k == n || k == 0) 
    return 1;
  if (memo[n][k] != -1) 
    return memo[n][k];
  return memo[n][k] = (bino(n - 1, k) + bino(n - 1, k - 1)) % MOD;
}

//Longest Common Subsequence
//Complejidad: O(|x| * |y|)
//Memoria: (|x| + 1)(|y| + 1)
//Se anexa reconstrucción:
string back(vector<vi> &c, string x, string y, int i, int j) {
  if (i == 0 || j == 0)
    return "";
  if (x[i] == y[j])
    return back(c, x, y, i - 1, j - 1) + x[i];
  if (c[i][j - 1] > c[i - 1][j])
    return back(c, x, y, i, j - 1);
  else
    return back(c, x, y, i - 1, j);
}

string LCS(string x, string y){  
  int l_x = x.length();  
  int l_y = y.length();  
  vector<vi> c(l_x + 1, vi(l_y + 1));    
  for (int i = 1; i <= l_x; i++){    
    for (int j = 1; j <= l_y; j++){     
      if (x[i - 1] == y[j - 1])      
        c[i][j] = c[i - 1][j - 1] + 1;     
      else      
        c[i][j] = max(c[i - 1][j], c[i][j - 1]);   
    }  
  }
  //Longitud del LCS = c[l_x][l_y]
  //Recosntrucción del LCS mediante backtracking
  string rec = back(c, x, y, x.size() - 1, y.size() - 1);
  for (int i = 1; i <= l_x; i++)
    for (int j = 1; j <= l_y; j++)
      if (c[i][j] == 1) {
        rec = x[i - 1] + rec;
        return rec;
      }
  return rec;
} 

//Longest increasing subsequence
//Complejidad: O(n^2)
//Memoria: (n)
//recibe un vector de números
int LIS(vi num){
  int n = num.size();
  vi lis(n, 1);
  for (int i = 1; i < n; i++){
    for (int j = 0; j < i; j++){
      if (num[i] > num[j] && lis[i] < lis[j] + 1)
        lis[i] = lis[j] + 1;
    }
  }
  for (int i = 0; i < n; i++)
    cout << lis[i] << " ";
  cout << endl;
  return lis[n-1];
}
//Coin Change
//Complejidad: O(val * pos)
//Memoria: (|val||N|)
//Se empieza con c(val, 0)
vi cambio;
int N = cambio.size();
int c(int val, int pos){
  if (val == 0)
    return 1;
  if (pos == N || val < 0)
    return 0;
  if (memo[val][pos] != -1)
    return memo[val][pos];
  return memo[val][pos] = c(val - cambio[pos], pos) + c(val, pos + 1);
}

//min coin change
//complejidad: O(valor)
//memoria: (n) lineal
/*
int n = valor;
  for (int j = 0; j <= n; j++)
    change(j);
  cout << me[n]; <- respuesta
*/
int me[MAX];
const int INF = (1<<30);
int change(int valor){
  if (valor == 0)
    return 0;
  if (valor < 0)
    return INF;
  if (me[valor] != -1)
    return me[valor];
  int ans = INF;
  for (auto cam : cambio)
    ans = min(ans, change(valor - cam));
  return me[valor] = ans + 1;
}

//Traveling Salesman Problem
//Complejidad: O(2^n * n^2)
//Memoria: (|n||2^n|) -> tamaño de la memorización
//se empieza con tsp(0, 1)
//la matriz dist es la matriz de adyacencia del grafo
int tsp(int pos, int mask){
  if (mask == (1<<n) - 1)
    return dist[pos][0];
  if (memo[pos][mask] != -1)
    return memo[pos][mask];
  int ans = INF;
  for (int i = 0; i < N; i++){
    if (mask & (1<<i) || pos == i)
      continue;
    ans = min(ans, dist[pos][i] + tsp(i, mask|(1<<i)));
  }
  return memo[pos][mask] = ans;
}

int main(){
  memset(memo, -1, sizeof memo);
  memset(me, -1, sizeof me);
  cout << bino(10, 5) << "\n";
  cout << LCS("abcddab", "bdcada") << "\n"; 
  return 0;
}
