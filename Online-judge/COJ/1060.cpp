#include <bits/stdc++.h>
using namespace std;
vector< int > num;
vector< string > conjunto;
set< int > buscar;
int N, cont;


bool comprobar( int num ){
	int aux = 0;
	while( num != 0 ){
		aux = num % 10;
		if( buscar.find( aux ) == buscar.end() ){
			return false;
		}
		num /= 10;
	}
	return true;
}

string bus( string s, int pos, int n ){
	if( pos == n && s.length() == 2 ){
		conjunto.push_back( s );
		return s;
	}else{
		bool aux1, aux2, aux3 = false;
		if( pos == n && s.length() == 3 ){
			for( int k = 0; k < conjunto.size(); k++ ){
				stringstream ss, ss1, ss2;
				ss << atoi( s.c_str() )*(conjunto[k][0]-'0');
				ss1 << atoi( s.c_str() )*(conjunto[k][1]-'0');
				ss2 << atoi( s.c_str() )*atoi( conjunto[k].c_str() );
				if( ss.str().length() == 3 && ss1.str().length() == 3 && ss2.str().length() == 4 ){
					aux1 = comprobar( atoi( s.c_str() )*(conjunto[k][0]-'0') );
					aux2 = comprobar( atoi( s.c_str() )*(conjunto[k][1]-'0') );
					aux3 = comprobar( atoi( s.c_str() )*atoi( conjunto[k].c_str() ) );
					if( aux1 && aux2 && aux3 ){
						cont++;
					}
				}
			}
			return s;
		}
	}
	string ans = "";
	for( int k = 0; k < num.size(); k++ ){
		stringstream ss;
		ss << num[k];
		ans = bus( s + ss.str(), pos + 1, n );
	}
	return ans;
}

int main(){

	//cin >> N;
	while( cin >> N ){
		int a = 0;
		for( int k = 0; k < N; k++ ){
			cin >> a;
			num.push_back( a );
			buscar.insert( a );
		}
		bus( "",0,2 );
		bus( "",0,3 );
		cout << cont << endl;
		num.clear();
		buscar.clear();
		conjunto.clear();
		cont = 0;
	}
}