#include<bits/stdc++.h>
using namespace std;

float R;
int N;
long double aux;

int main(){
	while(cin >> R >> N){
		cout<< setprecision(100)<<exp(N*log(R))<<endl;
		printf("%f\n",exp(N*log(R)));
	}
	return 0;
}