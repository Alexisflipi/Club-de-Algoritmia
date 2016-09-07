#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	double PI = 3.14;
	double R, A, B;

	cin >> s;
	cout << fixed;
	cout << setprecision(2);
	if (s == "circle"){
		cin >> R;
		cout << PI*R*R << "\n";
	}else{
		if (s == "triangle"){
			cin >> A >> B;
			cout << (A*B)/2.0 << "\n";
		}else{
			cin >> A >> B;
			cout << (A*B)/2.0 << "\n";
		}

	}
	return 0;
}