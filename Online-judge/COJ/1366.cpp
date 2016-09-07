#include <bits/stdc++.h>
#define lld long long int
using namespace std;

vector< lld > num;
vector< lld > ans;
int l, K, aux;

void combina( string forma, int pos ){
	if( pos == num.size() ){
		if( !forma.empty() ){
			//cout << forma << endl;
			aux = 0;
		    while( forma.find( "$" ) != -1 ){
		    	aux += atoi( forma.substr( 0,forma.find( "$" ) ).c_str() );
		    	forma.erase( 0,forma.find( "$" ) + 1 );
		    }
		    //cout << aux << endl;
		    ans.push_back( aux );
		}
		return;
	}
	stringstream ss;
	ss << num[ pos ];
	combina( forma + ss.str() + "$", pos + 1 );
	combina( forma, pos + 1 );
}

int pre( lld m ){
	l = m;
	num.push_back( 5 );
	for( int k = 0; k < m; k++ ){
		num.push_back( num[k]*5 );
	}
	combina( "",0 );
	sort( ans.begin(), ans.end() );
}

int main(){
	ios::sync_with_stdio( true );
	cin.tie( 0 );
	lld T, N;
	pre( 12 );
	//cout << ans.size() << endl;
	cin >> T;
	for( int k = 0; k < T; k++ ){
		cin >> N;
		cout << ans[ N-1 ] <<"\n";
	}
	return 0;
}
/*
4
1
2
3
9
*/