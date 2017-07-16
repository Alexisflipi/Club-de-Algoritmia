#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef vector<int> vi;
const lld MAX = 100000;
lld phi[MAX];

//Phi de Euler con criba
//Complejidad: O(n * log(n))
//Memoria: (n) lineal
void criba_euler_phi(){
  for (int k = 1; k < MAX; k++)
    phi[k] = k;
  for (int i = 2; i < MAX; i++){
    if (phi[i] == i)
      for (int j = i; j < MAX; j += i){
        phi[j] /= i;
        phi[j] *= i - 1;
      }
  }
}

//Divisores de cualquier número con criba
//Complejidad: O(n * log(n))
//Memoria: O(n * |d|) donde d son los divisores de cada número
void divisores(){
  vector<vi> divisors(MAX, vi());
  for (int i = 1; i < MAX; i++)
    for (int j = i; j < MAX; j += i)
      divisors[j].push_back(i);
  
  //Ejemplo: divisores de 45:
  for (auto d : divisors[45])
    cout << d << "\n";
  
}

//inverso modular aplicado a/b:
// [a * (b ^ MOD - 2)] % MOD

//Inverso Modular aplicado n C k
// [n! * (((n - k)! k!) ^ MOD-2)] % MOD


int main(){
  criba_euler_phi();
  divisores();
  return 0;
}
