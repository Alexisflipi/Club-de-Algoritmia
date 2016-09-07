#include<bits/stdc++.h>
using namespace std;

long long int N;
int main(){
	scanf("%lld",&N);
	printf("%lld\n",N-( (int)((N-1)/3)+1 ));
	return 0;
}