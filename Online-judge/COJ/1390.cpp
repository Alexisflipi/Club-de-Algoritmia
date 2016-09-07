#include <bits/stdc++.h>
using namespace std;
int i,N,k,aux,c,maxi,pos;
int a[5005],b[5005];
int main(){
	scanf("%d",&N);
	while(k<N){
	scanf("%d",&a[k]);
		c = a[k];
		for(i = 2; i <= a[k]; i++){
			if(c==1)
				break;
			if( c % i == 0){
					aux = i;
					while(c % i == 0)
						c /= i;
			}
		}
		if( aux > maxi){
			maxi=aux;
			pos=k;
		}
		k++;
	}
	printf("%d",a[pos]);
}
