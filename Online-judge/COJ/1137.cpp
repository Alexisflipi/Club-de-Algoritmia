#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int a, b;
	bool ban = false;
	int it = 0;

	while (!ban){
		set<int> bus;
		int cont = 0;
		int res = 0;
		while (cin >> a >> b){
			if (a == -1 && b == -1){
				ban = true;
				break;
			}
			if (a == 0 && b == 0) break;

			if (bus.find(a) == bus.end())
				bus.insert(a);

			if (bus.find(b) == bus.end())
				bus.insert(b);
			cont++;
		}
		if (ban) break;
		for (int i = 0; i < MAX/2; i++){
			if (bus.find(i) != bus.end())
				res++;
		}
		if (res-1 == cont || res == 0){
			cout << "Case " << ++it << " is a tree.\n";
		}else{
			cout << "Case " << ++it << " is not a tree.\n";
		}
	}
	return 0;
}