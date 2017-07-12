#include <bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;

typedef long long lli;
typedef vector<lli> vi;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	lli n;
	while (cin >> n and n) {
		vi num;
		num.pb(n);
		while (cin >> n and n)
			num.pb(n);
		vi ans;
		sort(num.begin(), num.end());
		for (lli i = 0; i < num.size() - 1; i++)
			ans.pb(-(num[i] - num[i + 1]));
		lli egcd = 0;
		for (auto &it : ans)
			egcd = __gcd(egcd, it);
		cout << egcd << '\n';
	}
	return 0;
}
