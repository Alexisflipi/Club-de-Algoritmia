#include <bits/stdc++.h>
#define MAX 105
using namespace std;

bool m[MAX];
vector<int> primes;

void criba(){
	for (int i = 3; i < MAX; i += 2)
		m[i] = true;
	m[2] = true;
	for (int i = 3; i * i < MAX; i += 2)
		if (m[i])
			for (int j = i * i; j < MAX; j += i)
				m[j] = false;
	primes.push_back(2);
	for (int i = 3; i < MAX; i++)
		if (m[i])
			primes.push_back(i);
}

vector<int> cu;
int get_powers(int n, int p){
    int res = 0;
    for (int power = p; power <= n; power *= p )
        res += n/power;
    return res;
}

void pre(int n){
	for (int i = 0; i < primes.size(); i++){
		int p = primes[i];
		int ans = get_powers(n, p);
		if (ans != 0)
			cu.push_back(ans);
	}
}
int main(){
	//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	criba();
	while (scanf("%d", &N)){
		if (N == 0) break;
		pre(N);
		printf("%3d! =", N);
		for (int i = 0; i < cu.size(); i++){
			if (i == 15)
				printf("\n      ");
			printf("%3d", cu[i]);
		}
		printf("\n");
		cu.clear();
	}
	return 0;
}