#include <bits/stdc++.h>
using namespace std;
#define lld long long int
lld n,i,a,b;
struct frac{
	lld x;
	lld y;
};
typedef struct frac Fraccion;

Fraccion vi[2],e[2];

void suma( lld a, lld b, lld c, lld d,lld i,lld n){
	lld nume = a*d + b*c;
	lld deno = b*d;
	if( c == 4)
		deno*=n;
	else
		if( c == 3 )
			deno*=n;
	lld aux = __gcd(nume,deno);
	e[i].x = nume/aux;
	e[i].y = deno/aux;
}

void multi( lld a , lld b, lld c,lld d,lld i){
	lld nume = a*c;
	lld deno = b*d;
	lld aux = __gcd(nume,deno);
	e[i].x = nume/aux;
	e[i].y = deno/aux;
}

int main(){
	scanf("%lld",&n);
	while( n!= 0){
		vi[0].x = 0;
		vi[0].y = 1;
		vi[1].x = 0;
		vi[1].y = 1;
		if(n == 1)
			printf("(x1,y1) = (0,0)\n");
		else{
			for( i = 2 ; i <= n ; i++){
				multi( i-2 , 1 , vi[0].x, vi[0].y,0);
				suma( e[0].x , e[0].y , -1*vi[1].x, vi[1].y,0,i);
				suma(e[0].x , e[0].y, 4,1,0,i);
				
				multi( i-1 , 1 , vi[1].x, vi[1].y,1);
				suma( e[1].x , e[1].y , -1*vi[0].x , vi[0].y,1,i);
				suma(e[1].x , e[1].y, 3,1,1,i);
				
				for(int j = 0; j<2; j++){
					vi[j].x = e[j].x;
					vi[j].y = e[j].y;
				}
			}
			if(n==2)
				printf("(x%lld,y%lld) = (%lld,%lld/%lld)\n",n,n,e[0].x,e[1].x,e[1].y);
			else
				printf("(x%lld,y%lld) = (%lld/%lld,%lld/%lld)\n",n,n,e[0].x,e[0].y,e[1].x,e[1].y);
		}
		scanf("%lld",&n);
	}
	return 0;
}