#include <bits/stdc++.h>
#define MAX 600
using namespace std;

int dist[MAX][MAX];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string S, T;
	cin >> S >> T;
	for (int i = 0; i <= S.length(); i++){
		dist[i][0] = i;
	}
	for (int i = 0; i <= T.length(); i++){
		dist[0][i] = i;
	}
	for (int i = 0; i <= S.length(); i++){
		for (int j = 0; j <= T.length(); j++){
			int edit = 1;
			if (S[i] == T[j]) edit = 0;
			dist[i+1][j+1] = min(dist[i][j] + edit, min(dist[i][j+1]+1, dist[i+1][j]+1));
		}
	}
	cout << dist[S.length()][T.length()] << "\n";
	
	return 0;
}