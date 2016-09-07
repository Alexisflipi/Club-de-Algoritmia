#include <bits/stdc++.h>
#define lld long double
#define MAX 1000000
using namespace std;

lld n;
lld k[MAX];
lld recu( int i){
	if( i == n)
		return i;
	else{
		k[i] = k[(int)(i-sqrt(i))] + k[(int)(log(i))]+k[(int)(i*pow(sin(i),2))];
		i++;
		recu( i );
	}
}


int main(){
	scanf("%ld",&n);
	while( n != -1){
		k[0] = 1;
		printf("%ld\n",k[recu(0)]%MAX);
		scanf("%ld",&n);
	}
	return 0;
}