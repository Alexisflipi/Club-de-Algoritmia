#include <bits/stdc++.h>
#define lld long long int
using namespace std;

int main(){
	lld N, a;
	cin >> N;
	vector<lld> num;
	lld sum = 1;
	for (lld i = 0; i < N; i++){
		cin >> a;
		sum *= a;
		num.push_back(a);
	}
	lld gcd = num[0];
	for (lld i = 0; i < N; i++){
		gcd = __gcd(gcd, num[i]);
	}
	cout << sum << " " << gcd << " " << sum/gcd << "\n";
	return 0;
}