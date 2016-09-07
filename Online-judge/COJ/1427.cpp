#include<bits/stdc++.h>
using namespace std;
long long int a,b,c,d;

int main(){
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	printf("%.2f",sqrt(abs(a-c)*abs(a-c)+abs(b-d)*abs(b-d)));
	return 0;
}