#include<bits/stdc++.h>
using namespace std;
int m[] = { 1,5,10,25,50 };
int memo[7500][6];
int coin( int valor , int tipo ){
	if( valor == 0 ){
		return 1;
	}
	if( tipo == 5 || valor < 0 ){
		return 0;
	}
	if( memo[ valor ][ tipo ] != -1 ){
		return memo[ valor ][ tipo ];
	}
	memo[ valor ][ tipo ] = coin( valor - m[tipo] , tipo ) + coin( valor , tipo + 1 );
	return memo[ valor ][ tipo ];
}
int main(){
	int n;
	memset( memo , -1 , sizeof memo );
	while( scanf( "%d",&n) != EOF){
		printf("%d\n", coin( n,0 ) );
	}
	return 0;
}