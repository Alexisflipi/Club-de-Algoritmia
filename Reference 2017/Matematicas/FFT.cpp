#include <bits/stdc++.h>
using namespace std;

typedef vector<double> Vector;
 
const double M_2PI = 2 * M_PI;
 
struct Complejo {
  double real, imag;
  Complejo() : real(), imag() {}
  Complejo(double r, double i) : real(r), imag(i) {}

  Complejo operator+(const Complejo& c) {
    return Complejo(real + c.real, imag + c.imag);
  }
  Complejo operator-(const Complejo& c) {
    return Complejo(real - c.real, imag - c.imag);
  }
  Complejo operator*(const Complejo& c) {
    return Complejo(real * c.real - imag * c.imag,
                    real * c.imag + imag * c.real);
  }
};
 
vector<Complejo> FastAndFourier(
  const vector<Complejo>& a, int k = 1) {

  int n = a.size();
  if (n == 1) return a;
  vector<Complejo> par, impar;
  for (int i = 0; i < n; ++i)
    if (i & 1) par.push_back(a[i]);
    else impar.push_back(a[i]);
  impar = FastAndFourier(impar, k);
  par = FastAndFourier(par, k);

  vector<Complejo> fourier(n);
  Complejo w(1, 0), wn(cos(-k * M_2PI/n),
                       sin(-k * M_2PI/n));
  for (int i = 0; i < n/2; w = w * wn, ++i) {
    fourier[i + n/2] = impar[i] - w * par[i];
    fourier[i] = impar[i] + w * par[i];
  }
  return fourier;
}
 
vector<Complejo> InvFastAndFourier(
  const vector<Complejo>& a) {
  vector<Complejo> ifft = FastAndFourier(a, -1);
  for (int i = 0; i < ifft.size(); ++i)
    ifft[i].real /= ifft.size(),
    ifft[i].imag /= ifft.size();
  return ifft;
}
 
Vector ConvolucionDiscreta(
    const Vector& a, const Vector& b) {
     
  int n = a.size() + b.size() - 1;
  int p = 1; while (p < n) p <<= 1;

  vector<Complejo> A(p), B(p), C(p);
  for (int i = 0; i < a.size(); ++i)
    A[i] = Complejo(a[i], 0);
  for (int i = 0; i < b.size(); ++i)
    B[i] = Complejo(b[i], 0);

  A = FastAndFourier(A);
  B = FastAndFourier(B);
  for (int i = 0; i < p; ++i)
    C[i] = A[i] * B[i];
  C = InvFastAndFourier(C);

  Vector convolucion(n);
  for (int i = 0; i < n; ++i)
    convolucion[i] = C[i].real;
  return convolucion;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  int n = s.size();
  Vector a(n);
  Vector b(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') a[i] = 1;
    if (s[i] == 'B') b[n - 1 - i] = 1;
  }
  Vector ans = ConvolucionDiscreta(a, b);
  for (int i = n; i < 2 * n - 1; i++)
    cout << ans[i] << "\n";
  return 0;
}
