#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

bool m[ MAX ];
int n;

int main(){
	int tam = 999983;
	for( int i = 3; i <= tam; i +=2 ){
		m[ i ] = true;
	}
	for( int i = 3; i*i <= tam; i += 2 ){
		if( m[i] ){
			for( int j = i*i; j <= tam; j += i ){
				m[ j ] = false;
			}
		}
	}
	cin >> n;
	while( n != 0 ){
		if( n%2 != 0 || n < 6){
			cout << "Goldbach's conjecture is wrong." << "\n";
		}else{
			int k = 0;
			for( k = 3; k <= n/2; k += 2 ){
				if( m[k] && m[ n - k ] ){
					cout << n << " = " << k << " + " << n-k << "\n";
					break;
				}
			}
		}
		cin >> n;
	}
	return 0;
}