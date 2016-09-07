#include<bits/stdc++.h>
using namespace std;
# define lld long long int
lld suma,a,b;
int T,i;
int main()
{
	scanf("%d",&T);
	while(T--){
		suma=0;
		scanf("%lld %lld",&a,&b);
		for(i=a ; i<=b ; i++){
			suma+=i*(i+1)*(i+2);
		}
		printf("%lld\n",suma%100);
	}
	return 0;
}