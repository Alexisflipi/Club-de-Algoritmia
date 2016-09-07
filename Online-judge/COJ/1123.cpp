#include <bits/stdc++.h>
#define lld long long int
using namespace std;

vector< lld > num;

lld power( lld a, lld n ){
    lld ret = 1;
    while ( n != 0 ){
        if ( n % 2 == 1 ) ret *= a;
        a *= a;
        n /= 2;
    }
    return ret;
}
void ugly(){
    int cont = 0;
    for ( int i = 0; i < 35; i++ ){
        for ( int j = 0; j < 35; j++ ){
            for ( int k = 0; k < 35; k++ ){
                lld aux = power( 2, i )*power( 3, j )*power( 5, k );
                if ( aux > 0 )
                    num.push_back( aux );
            }
        }
    }
    sort( num.begin(), num.end());
}

int main(){
    lld N = 0;
    ugly();
    while ( cin >> N && N != 0 ){
        cout << num[ N-1 ] << "\n";
    }
    return 0;
}