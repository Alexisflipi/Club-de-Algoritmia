#include<bits/stdc++.h>
#define lld long long int
using namespace std;

lld maxi,a,b,c,i;
bool d;
lld maximo( lld n, lld aux){
	if( n == 1)
		return aux;
	if( n%2 == 0 )
		return maximo( n/2 , aux + 1);
	return maximo( 3*n + 1 , aux + 1);
}

int main(){
	while( scanf("%lld %lld",&a,&b)!= EOF){
		d = false;
		if( a > b){
			swap(a,b);
			d = true;
		}
		for( i = a ; i<= b ; i++){
			c = maximo(i,1);
			if( c > maxi )
				maxi = c;
		}
		if( d == true)
			swap(a,b);
		printf("%lld %lld %lld\n",a,b,maxi);
		maxi = 0;
	}
	return 0;
}
//1079
//1861