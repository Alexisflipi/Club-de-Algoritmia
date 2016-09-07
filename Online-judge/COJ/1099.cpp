#include<bits/stdc++.h>
using namespace std;
int p[3];
int aux,n;

int main(){
		while(1){
			if( aux == 0){
				scanf("%d",&n);
				if( n == 0)
					break;
				else{
					p[aux] = n;
					aux++;
				}
			}else{
				if(aux == 3){
					if( p[0]*p[0] + p[1]*p[1] == p[2]*p[2] || p[0]*p[0] + p[2]*p[2] == p[1]*p[1] || p[2]*p[2] + p[1]*p[1] == p[0]*p[0]){
						printf("right\n");
						
					}else
						printf("wrong\n");
					aux=0;
				}else{
					scanf("%d",&n);
					p[aux] = n;
					aux++;
				}
			}
		}
	return 0;
}