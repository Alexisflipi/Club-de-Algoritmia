#include <bits/stdc++.h>
using namespace std;

int T,n,m,i,j,a;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		int tab[n];
		for( i=0 ; i < n; i++)
			tab[i] = 0;
		for( i=0 ; i<m ; i++ ){
			for( j=0 ; j<n ; j++ ){
				scanf("%d",&a);
				tab[j]+=a;
				//printf("%d  ",tab[j]);
			}
			//printf("\n");
		}
		for( i=0 ; i < n; i++)
			if( tab[i] == *max_element(tab,tab+n) ){
				printf("%d\n",i+1);
				break;
			}
	}
	return 0;
}