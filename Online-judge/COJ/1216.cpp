#include <bits/stdc++.h>
#define lld long long int
using namespace std;

lld T, n, a, ans, cont;
vector< lld > num;
set< lld > bus;

lld dp( lld valor, lld pos ){
	if( valor == 0 ){
		cout << pos << endl;
		return 1;
	}
	if( valor < 0 || pos == cont )
		return 0;
	ans = dp( valor - num[ pos ], pos ) + dp( valor, pos + 1 );
	return ans;
}

int main(){
	ios::sync_with_stdio( false );
	cin.tie( 0 );
	
	cin >> T;
	for( int k = 0; k < T; k++ ){
		cin >> n;
		for( int i = 0; i < n; i++ ){
			cin >> a;
			if( bus.find( a ) == bus.end() || a == 47 ){
				num.push_back( a );
				bus.insert( a );
				cont++;
				cout << a << endl;
			}
		}
		cout << dp( 47,0 ) << endl;
	}
	return 0;
}
/*
2

13
2 7 1 8 2 8 1 8 2 8 4 5 9

7
2 47 10047 47 1047 47 47
*/