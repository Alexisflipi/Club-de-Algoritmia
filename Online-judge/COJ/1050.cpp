#include <bits/stdc++.h>
using namespace std;

int aux,i,N;
int main(){
	scanf("%d",&N);
	for(i=1; i<N ; i++)
		if(__gcd(i,N) == 1)
			aux++;
	printf("%d\n",aux);
	return 0;
}