#include <bits/stdc++.h>
#define MAX 500004
#define lld long long int
using namespace std;

int m[ 500005 ];

void divisores( ){
	//memset( m, 1, sizeof m );
	for( int i = 2; i < MAX; i++ ){
		for( int j = i; j < MAX; j += i ){
			if( j == i )
				continue;
			m[ j ] += i;
		}
	}
}

int main(){
	ios::sync_with_stdio( true );
	cin.tie( 0 );
	divisores();
	lld T, N;
	cin >> T;
	for ( int k = 0; k < T; k++ ){
		cin >> N;
		if( N == 1 ){
			cout << "0" << endl;
			continue;
		}
		cout << m[ N ] + 1 << "\n";
	}
	return 0;
}
/*
3
2
10
20
*/