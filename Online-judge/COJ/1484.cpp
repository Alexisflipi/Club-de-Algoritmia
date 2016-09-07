#include <bits/stdc++.h>
using namespace std;

double a, maxi;
int main(){
	int n;
	int ans = 0;
	cin >> n;
	for( int k = 0; k < n; k++ ){
		cin >> a;
		if( a >= maxi ){
			maxi = a;
			ans = k+1;
		}
	}
	cout << ans << "\n";
	return 0;
}
/*
7
15.00
35.54
11.32
11.32
21.00
15.00
35.54
*/