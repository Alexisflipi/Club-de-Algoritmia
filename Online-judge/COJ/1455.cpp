#include <bits/stdc++.h>
using namespace std;

long long int N,a,b,aux,i,k,sum;
int main(){
	scanf("%lld %lld %lld",&N,&a,&b);
	/*for( i=a ; i<=b ; i++){
		if( __gcd(N,i) == 1){
			printf("%lld %lld\n",N,i);
			sum++;
		}
	
	}*/
	if( N%2 == 0)
		N = 2;
	k = (int)(b/N) - (int)(a/N) + 1;
	
	printf("%lld",(b-a+1)-k);
	//printf("%lld",sum);
	return 0;
}
//1000000000000000000
/*
scanf("%lld %lld %lld",&N,&a,&b);
	i = 1;
	while( i*N <= b){
		aux++;
		i++;
	}
	printf("%lld",(b-a+1)-aux);

*/