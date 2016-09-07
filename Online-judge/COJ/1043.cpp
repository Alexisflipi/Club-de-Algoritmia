#include <bits/stdc++.h>
using namespace std;

int T,i,a,p;

int bina(int a){
	if( a == 0)
		return 0;
	else{
		if( a%2 == 1 && a != 1)
			printf("%d ",i);
		else
			if( a == 1)
				printf("%d",i);
		i++;
		bina( (int)(a/2));
	}
	return 0;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&p);
		bina( p );
		printf("\n");
		i=0;
	}
	return 0;
}