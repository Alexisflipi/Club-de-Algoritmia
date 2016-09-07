#include <bits/stdc++.h>
using namespace std;

int score[10005];
int main(){
	int T, m, n, points, minu;
	cin >> T;
	for (int c = 0; c < T; c++){
		memset (score, 0, sizeof score);
		cin >> m >> n;
		for (int i = 0; i < n; i++ ){
			cin >> points >> minu;
			for (int j = minu; j <= m; j++){
				if (score[ j - minu ] + points > score[ j ])
					score[ j ] = score[ j - minu ] + points;
			}
		}
		cout << score[ m ] << "\n";
	}
	return 0;
}
/*
1
300 4
100 60
250 120
120 100
35 20
*/