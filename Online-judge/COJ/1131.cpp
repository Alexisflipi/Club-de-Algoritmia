#include <bits/stdc++.h>
#define MAX 500
#define lld long long int
using namespace std;

bool m[ MAX ];
int factor[ MAX ];
lld num[ MAX ];
lld den[ MAX ];

void criba(){
	for( int i = 3; i < MAX; i += 2 ){
		m[ i ] = true;
		factor[ i-1 ] = 2;
	}
	m[ 2 ] = true;
	for( int i = 3; i*i < MAX; i += 2 )
		if( m[ i ] )
			for( int j = i*i; j < MAX; j += i ){
				m[ j ] = false;
				factor[ j ] = i;
			}
	for( int i = 3; i < MAX; i += 2 )
		if( m[ i ] )
			factor[ i ] = i;
}

lld fprimes(){
	lld	ans = 1;
	for( int i = 0; i < MAX; i++ ){
		if( num[ i ] != 0 ){
			ans = ans*( num[ i ]-den[ i ] + 1 );
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio( true );
	cin.tie( 0 );

	int N, K;
	criba();
	while( cin >> N >> K ){
		memset( num, 0, sizeof num );
		memset( den, 0, sizeof den );
		int n = 0;
		for( int i = N; i > N - K; i-- ){
			n = i;
			while( n != 1 ){
				num[ factor[ n ] ]++;
				n /= factor[ n ];
			}
		}
		for( int i = K; i > 1; i-- ){
			n = i;
			while( n != 1 ){
				den[ factor[ n ] ]++;
				n /= factor[ n ];
			}
		}
		cout << fprimes() << "\n";
	}
	return 0;
}
/*
5 1
6 3
10 4
*/