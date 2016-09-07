#include<bits/stdc++.h>
using namespace std;
int T,N;
float R;
double aux;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%f %d",&R,&N);
		printf("%.4f %.4f\n",2*N*R*sin(3.141592653589793/(N+0.0)),2*N*R*tan((3.141592653589793)/N));
	}
	return 0;
}