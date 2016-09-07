#include<bits/stdc++.h>
using namespace std;
int i,n; 
int main()
{ 
	while(scanf("%d",&i) != EOF){
		n = i+1;
		printf("%d %d\n", (i*(i+1)*(2*i+1))/6, (n*n)*(n*n-2*n+1)/4);
	}
	return 0; 
}