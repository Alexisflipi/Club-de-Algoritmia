#include <bits/stdc++.h>
using namespace std;
#define lld long long int
int T;
lld N,M;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld %lld",&N,&M);
		if( N == M ){
			if( M%2 == 0 )
				printf("L\n");
			else
				printf("R\n");
		}else{
			if( N > M ){
				if( M%2 == 0 )
					printf("U\n");
				else
					printf("D\n");
			}else{
				if( N%2 == 0 )
					printf("L\n");
				else
					printf("R\n");
			}
		}
	}
	return 0;
}