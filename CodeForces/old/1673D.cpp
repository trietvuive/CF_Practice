#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

ll solve() {
	ll b0, bd, bn, c0, cd, cn;
	cin >> b0 >> bd >> bn >> c0 >> cd >> cn;
	
	ll b1 = (b0 + bd * (bn - 1)), c1 = (c0 + cd * (cn - 1));
	if(c0 < b0 || c1 > b1 ||
		cd % bd != 0 || (c1-b1) % bd != 0) 
		return 0;

	if((b0 > c0 - cd) || (b1 < c1 + cd)) return -1;

	set<int> s;
	for(int i = 1; i * i <= cd; ++i) {
		if(cd % i == 0) {
			s.insert(i);
			s.insert(cd / i);
		}
	}

	ll ans = 0;
	for(int ad : s) {
		if(lcm(ad, bd) != cd) continue;
		ans = (ans + (cd/ad) * (cd/ad)) % MOD;
	}

	return ans;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc;
	cin >> tc;
	while(tc--) {
		cout << solve() << '\n';
	}
}
