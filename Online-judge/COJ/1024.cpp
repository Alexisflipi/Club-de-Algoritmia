#include<bits/stdc++.h>
using namespace std;

int T,i;
float c,sum;

int main(){
	scanf("%f",&c);
	while( c != 0.00 ){
		i=2;
		sum=0.0;
		while( sum < c){
			sum += (1.0/i);
			i++;
		}
		printf("%d card(s)\n",i-2);
		scanf("%f",&c);
	}
	return 0;
}