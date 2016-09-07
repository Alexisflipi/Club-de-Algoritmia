#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	string s;
	cin >> T;
	for( int k = 0; k < T, k++ ){
		cin >> s;
		if( s.find( "0" ) == -1 || s.find( "5" ) == -1 ){
			cout << "impossible" << "\n";
			continue;
		}
	}
	return 0;
}