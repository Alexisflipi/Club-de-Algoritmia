#include <bits/stdc++.h>
#define MAX 1e6
#define res 1000007
#define lld long long int
using namespace std;
int T;
lld a,b,i,j;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld %lld",&a,&b);
		for(i=1 ; i <= MAX ; i++){
			if( i*i*i >= a){
				break;
			}
		}
		for(j=MAX ; j>=1 ; j--){
			if( j*j*j <= b){
				break;
			}
		}
		if(i==j)
			printf("%lld\n",b%res);
		else
			printf("%lld\n",((((j*(j+1)/2)%res*(j*(j+1)/2)%res)%res - (((i*(i-1))/2)%res*(i*(i-1)/2)%res)%res)+res)%res );
	}
	return 0;
}