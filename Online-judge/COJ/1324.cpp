#include <bits/stdc++.h>
using namespace std;

vector< int > num;
int main(){
	int a = 0;
	for( int k = 0; k < 9; k++ ){
		cin >> a;
		num.push_back( a );
	}
	sort( num.begin(), num.end() );
	return 0;
}