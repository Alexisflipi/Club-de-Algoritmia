#include<bits/stdc++.h>
using namespace std;

int i,N;

int main(){
	scanf("%d",&N);
	int a[N];
	while( i<N ){
		scanf("%d",&a[i]);
		i++;
	}
	sort(a,a+N);
	for( i = 0 ; i<N ;i++)
		printf("%d\n",a[i]);
	return 0;
}