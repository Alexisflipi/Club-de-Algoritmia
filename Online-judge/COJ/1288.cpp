#include <bits/stdc++.h>
using namespace std;
int T,i;
string N;
long long int aux1,aux2;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> T;
	while( T-- ){
		cin >> N;
		if( N[0] == '-')
			N = N.substr(1,N.length()-1);
		aux1 = N[N.length()-1] - '0';
		if( N.length() == 1)
			aux2 = N[0] - '0';
		while( N.length() != 1){
			aux2=0;
			for( i=0 ; i < N.length() ; i++)
				aux2 += N[i]-'0';
			stringstream s;
			s << aux2;
			N = s.str();
		}
		if( aux1%2 == 0 && aux2%3 == 0)
			printf("YES\n");
		else
			printf("NO\n");
		aux1 = 0;
		aux2 = 0;
	}
	
	return 0;
}