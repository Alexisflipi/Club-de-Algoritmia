#include <bits/stdc++.h>
using namespace std;

int main(){
	cout.precision(2);
	cout << fixed;
	ios::sync_with_stdio( true );
	cin.tie( 0 );
	int T = 0;
	cin >> T;
	double area = 0.0, s = 0.0;
	for( int i = 0; i < T; i++ ){
		cin >> area >> s;
		double d1 = (s + sqrt( abs(s*s - 8*area )))/2.0;
		//cout << d1 << endl;
		//double d2 = (s - sqrt( abs(s*s - 8*area) ))/2.0;
		//cout << d2 << endl;
		double dmax = d1;
		double Dmax = (s - dmax);
		dmax /= 2.0;
		Dmax /= 2.0;
		double L = sqrt( (dmax)*(dmax) + (Dmax)*(Dmax) );
		cout << L << "\n";
	}
	return 0;
}
/*
3
1.000 2.828
1.000 3.000
0.684 3.456
*/