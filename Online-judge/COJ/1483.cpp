#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	string s;
	int a, b;
	cin >> s;
	if (s == "square"){
		cin >> a;
		cout << a*a << "\n";
	}else{
		cin >> a >> b;
		cout << a*b << "\n";
	}
	return 0;
}