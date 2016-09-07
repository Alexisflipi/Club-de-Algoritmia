#include <bits/stdc++.h>
using namespace std;
int a;
int main(){
	scanf("%d",&a);
	if( a > 0 )
		printf("%d\n",(a*(a+1))/2);
	else
		printf("%d\n",-1*((abs(a)*(abs(a)+1))/2) + 1);
	return 0;
}