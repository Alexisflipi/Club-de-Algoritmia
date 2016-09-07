#include<bits/stdc++.h>
using namespace std;
int i,j,sum;
string a,b;
int main(){
	cin >> a >> b;
	for( i = 0 ; i < a.length() ; i++)
		for( j = 0 ; j < b.length() ; j++)
			sum += (a[i]-'0')*(b[j]-'0');
	cout << sum << endl;
	return 0;
}