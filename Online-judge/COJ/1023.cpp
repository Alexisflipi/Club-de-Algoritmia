#include <bits/stdc++.h>
using namespace std;

float din,sum;
int T=12;

int main(){
	while(T--){
		scanf("%f",&din);
		sum+=din;
	}
	printf("$%.2f\n",(sum/12));
	return 0;
}