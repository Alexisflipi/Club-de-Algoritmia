#include <bits/stdc++.h>
using namespace std;
int x,y,N;

int main(){
	scanf("%d",&N);
	while(N--){
		scanf("%d %d",&x,&y);
		if( x-y == 2 || x == y ){
			if( x%2 == 0 ){
				printf("%d\n",x+y);
			}else{
				printf("%d\n",(x+y)-1);
			}
		}else{
			printf("No Number\n");
		}
	}
	return 0;
}