#include <bits/stdc++.h>
using namespace std;

//Problema:
//Se tiene un juego de dardos disparados hacia
//un tablero, participan dos personas y el
//primero que acerte en el tablero, gana.
//La primera persona tiene una probabilidad
//de acertar de a/b mientras que
//la segunda es de c/d
//¿Cuál es la probabilidad de que la 
//primera persona gane?
//Solución:
//Se utiliza una distribución geométrica uniforme:
//P(x = k) = p * (q)^k
//donde p = a/b y q = (1 - c/d)*(1 - a/b)
//Se realiza la suma infinita desde k = 0, 1, ...
//Convergiendo a:
//P(ganar) = p * (1 / (1 - q))

int main(){
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << fixed;
  cout << setprecision(6);
  double p = a/b;
  double q = (1 - a/b)*(1 - c/d);
  cout << p * (1/(1 - q)) << "\n";
}

//Probrema:
//Se tiene un dado de m caras.
//Se realizan n lanzamientos con ese dado y se
//registran los puntos del dado.
//Se toma el valor máximo en los n lanzamientos
//efectuados por el dado
//Calcular el valor esperado del máximo de puntos

//Solución:
//Se requiere el valor esperado del máximo en puntos
//Al realizar todos los posibles combinaciones de
//ensayos de los lanzamientos, se quiere contar
//el número de veces que una cara del dado haya 
//sido máxima en un ensayo (lanzar el dado n veces)
//para las caras = 1, 2, 3, ..., m se aplica 
//combinatoria para contar. Se llega a la fórmula:

double genera(int N, int M){
  double expect_value = 0.0;
  for (int i = 1; i <= M; i++){
    double r = double(i)/double(M);
    double s = double(i - 1)/double(M);
    expect_value += (Expo(r, N) - Expo(s, N)) * double(i);
  }
  return sum;
}

int main(){
  int N, M;
  double maxi = 0.0;
  cin >> M >> N;
  cout << fixed;
  cout << setprecision(4);
  cout << genera(N, M) << "\n";
}


// Problema: Hay n personas formadas para abordar
// la escalera eléctrica, la i persona tiene una 
// probabilidad p de empezar a subir y 1-p para 
// quedarse en la misma posición en el tiempo t
// ¿Cuál es el valor esperado del número de personas
// que se encuentran en la escalera después de t segundos?

const int MAXN = 2016;
double dp[MAXN][MAXN];

double elevator(int n, double p, int t){
  dp[0][0] = 1.0;
  for (int i = 0; i <= t; i++){
    for (int j = 0; j <= n; j++){
      if (j == n){
        dp[i + 1][j] += dp[i][j];
      }else{
        dp[i + 1][j] += dp[i][j] * (1.0 - p);
        dp[i + 1][j + 1] += dp[i][j] * p;
      }
    }
  }
  double expected_value = 0.0;
  for (int i = 0; i <= n; i++)
    expected_value += dp[t][i] * i;
  return expected_value;
}

int main(){
  int n, t;
  double p;
  cin >> n >> p >> t;
  cout << fixed;
  cout << setprecision(6);
  cout << elevator(n, p, t) << "\n";
}

