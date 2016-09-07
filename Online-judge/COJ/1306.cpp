#include <bits/stdc++.h>
using namespace std;
int T,aux;
string N;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> T;
	while( T-- ){
		cin >> N;
		if( N.length() == 1)
			aux = atoi( N.c_str() );
		else
			aux = atoi( N.substr(N.length()-2,2).c_str() );
		if( aux%4 == 0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}