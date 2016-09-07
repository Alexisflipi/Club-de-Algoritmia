#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, N, a;
	cin >> T;
	for (int i = 0; i < T; i++){
		int even = 0;
		int odd = 0;
		cin >> N;
		for (int j = 0; j < N; j++){
			cin >> a;
			if (a % 2 == 0) even++;
			else odd++;
		}
		cout << even << " even and " << odd << " odd.\n";
	}
	return 0;
}