#include<bits/stdc++.h>
using namespace std;

int impar,par;
string s;
int main(){
	cin >> s;
	while ( s != "0" ){
		for(int i = 0 ; i < s.length() ; i ++ ){
				if( i%2 == 1 )
					impar += s[i] - '0';
				else
					par += s[i] - '0';
		}
		if ( abs(par - impar)%11 == 0 )
			cout << s << " is a multiple of 11." << "\n";
		else
			cout << s << " is not a multiple of 11." << "\n";
		cin >> s;
		impar = 0; par = 0;
	}
	return 0;
}
/*
112233
30800
2937
323455693
5038297
112234
0
*/