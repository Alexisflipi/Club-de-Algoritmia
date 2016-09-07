#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

bool m[ MAX ];
vector< int > primes;

void criba(){
	for( int i = 3; i < MAX; i += 2 ) m[ i ] = true;
	m[ 2 ] = true;
	for( int i = 3; i*i < MAX; i += 2 ){
		if( m[ i ] )
			for( int j = i*i; j < MAX; j += i )
				m[ j ] = false;
	}
	for( int i = 2; i < MAX; i++ )
		if( m[ i ] )
			primes.push_back( i );
}

bool checar( int pal ){
	if( pal == 1 )
		return false;
	for( int i = 0; i >= 0; i++ ){
		if( pal % primes[ i ] == 0 )
			return false;
		if( primes[ i ] > ( pal/ primes[ i ] ) )
			break;
	}
	return true;
}

vector< int > temp;
vector< int > act;

void genera( int N ){
	for( int j = 1; j < N; j++ ){
		for( int i = 0; i < temp.size(); i++ ){
			for( int k = 1; k <= 9; k += 2 ){
				if( checar( temp[ i ]*10 + k ) ){
					act.push_back( temp[ i ]*10 + k );
				}
			}
		}
		if( j == N-1 )
			break;
		temp.clear();
		temp = act;
		act.clear();
	}
}

int main(){
	int n;
	criba();

	while( cin >> n ){
		temp.push_back( 2 );
		temp.push_back( 3 );
		temp.push_back( 5 );
		temp.push_back( 7 );
		if( n == 1 ){
			for( int k = 0; k < temp.size(); k++ ){
				cout << temp[ k ] << endl;
			}
		}
		genera( n );
		sort( act.begin(), act.end() );
		for( int i = 0; i < act.size(); i++ ){
			cout << act[ i ] << endl;
		}
		act.clear();
		temp.clear();
	}
	return 0;
}
/*
4
*/