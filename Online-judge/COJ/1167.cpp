#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int main(){
	int N, M;
	string s;
	cin >> N;
	for (int i = 0; i < N; i++){
		vector<string> t;
		cin >> M;
		for (int j = 0; j < M; j++){
			cin >> s;
			t.push_back(s);
		}
		int ans = -INF;
		int aux = t[0].length();
		ans = max(ans, aux);
		int sum = ans;
		for (int j = 1; j < M; j++){
			int l = t[j].length();
			if (t[j][0] == t[j - 1][t[j - 1].length()-1]){
				sum += l;
			}else{
				sum = l;
			}
			ans = max(ans, sum);
		}
		cout << ans << "\n";
	}
	return 0;
}