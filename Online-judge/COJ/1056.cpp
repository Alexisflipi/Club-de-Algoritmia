#include <bits/stdc++.h>
#define lld long long int
using namespace std;

int n, s;
lld base( int base, int num ){
	lld	 total = 0, coeficiente = 1;
	while ( num != 0 ){
        total = total + coeficiente*(num%base);
        num = num/base;
        coeficiente *= 10;
    }
    return total;
}
bool palindromo( string s ){
	string aux;
	for( int i = s.length(); i >= 0 ; i-- ){
		aux += s[i];
	}
	aux.erase( 0 , 1 );
	if( aux == s )
		return true;
	else
		return false;
}

int main(){
	while( cin >> n >> s ){
		int cont = 0;
		for( int i = s+1 ; i > 0; i++ ){
			int aux = 0;
			for( int k = 2; k < 11 ; k++ ){
				stringstream ss;
				ss << base( k , i );
				if( palindromo( ss.str() )){
					aux++;
				}
				if( aux == 2 ){
					cout << i << endl;
					cont++;
					break;
				}
			}
			if( cont == n )
				break;
		}
	}
}