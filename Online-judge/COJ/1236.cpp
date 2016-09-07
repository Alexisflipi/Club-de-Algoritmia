#include <bits/stdc++.h>
using namespace std;

int a,b,c,d,sum;
int p,m,g,aux,i,j,n;
bool inter[1010],inter2[1010];

int llenar(int n,int x,int y,int z){
		for( i=aux ; i< aux+n; i++){
			if(i==1000){
				if(inter[z-1] == true){
					j=0;
					aux=0;
					return 1;
				}else{
					j=0;
					aux=0;
					return 0;
				}
			}else
				if( j%2 == 0 )
					inter[i]=true;
				else
					inter[i]=false;
		}
		aux+=n;
		j++;
		if( j%2 == 0 )
			llenar(x,x,y,z);
		else
			llenar(y,x,y,z);
}

int main(){
	scanf("%d %d %d %d",&a,&b,&c,&d);
	for(int k=0;k<3;k++){
		scanf("%d",&p);
		if( llenar(a,a,b,p) == 1 && llenar(c,c,d,p) == 1)
			printf("both\n");
		else
			if(llenar(a,a,b,p) == 1 || llenar(c,c,d,p) == 1)
				printf("one\n");
			else
				printf("none\n");
	}
	return 0;
}
