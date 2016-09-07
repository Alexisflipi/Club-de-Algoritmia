#include <bits/stdc++.h>
using namespace std;

string bin(int n){
	string aux = "";
	while (n != 0){
		int i = n % 2;
		stringstream ss;
		ss << i;
		aux = ss.str() + aux;
		n /= 2;
	}
	return aux;
}

long long int cont(string s){
	long long int cont = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '1') cont++;
	return cont;
}
int main(){
	int N;
	while (cin >> N){
		if (N == 0) break;
		string s = bin(N);
		long long int i = cont(s);
		cout << "The parity of " << s << " is "<< i <<" (mod 2).\n";
	}
	return 0;
}