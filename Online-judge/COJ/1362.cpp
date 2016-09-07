#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio( true );
	cin.tie( 0 );

	int A, B, C;
	while( cin >> A >> B >> C && A != 0 && B != 0 && C != 0 ){
		if( A >= B )
			swap( A,B );
		if( C % __gcd( A, B ) == 0 )
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	return 0;
}
/*
1 9 1
5 10 19
0 0 0
*/