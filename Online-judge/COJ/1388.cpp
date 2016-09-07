#include<bits/stdc++.h>
#define lld long long int
using namespace std;

lld T,a,b;
lld ex( lld n, lld pos){
	cout << n << " "<< pos-1<<"\n";
	if( pos == b)
		return n;
	return ex( (n*a)%10 , pos + 1 );
}
int main(){
	scanf("%lld",&T);
	while( T-- ){
		scanf("%lld %lld",&a,&b);
		switch( a%10 ){
			case 0:
				printf("%lld",0);
				break;
			case 1:
				printf("%lld",1);
				break;
			case 2:
				switch( b%4 ){
					case 0:
						printf("%lld",2);
						break;
					case 1:
						printf("%lld",4);
						break;
					case 2:
						printf("%lld",8);
						break;
					default:
						printf("%lld",6);
						break;
				}
				break;
			case 3:
				switch( b%4 + 1 ){
					case 1:
						printf("%lld",3);
						break;
					case 2:
						printf("%lld",9);
						break;
					case 3:
						printf("%lld",7);
						break;
					default:
						printf("%lld",1);
						break;
				}
				break;
			case 4:
				if( b%2 == 0)
					printf("%lld",6);
				else
					printf("%lld",4);
				break;
			case 5:
				printf("%lld",5);
				break;
			case 6:
				printf("%lld",6);
				break;
			case 7:
				switch( b%4 + 1 ){
					case 1:
						printf("%lld",7);
						break;
					case 2:
						printf("%lld",9);
						break;
					case 3:
						printf("%lld",3);
						break;
					default:
						printf("%lld",1);
						break;
				}
				break;
		}
		if( b == 0)
			printf("%lld\n",1);
		else
			printf("%lld\n",ex(a%10,1));
	}
	return 0;
}