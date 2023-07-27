#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

ll MOD = 1e9 + 7, n, b, k, x;

struct mat {
	ll s[105][105];
	friend mat operator * (mat& xx, mat& yy) {
		mat z;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < x; j++) {
				z.s[i][j] = 0;
				for (int l = 0; l < x; l++) {
					z.s[i][j] += xx.s[i][l] * yy.s[l][j];
					z.s[i][j] %= MOD;
				}
			}
		}
		return z;
	}
} q;

void solve() {
	cin >> n >> b >> k >> x;
	for(int i = 0; i < n; ++i) {
		ll a; cin >> a;
		for(int j = 0; j < x; ++j) 
			q.s[j][(10*j + a) % x]++;
	}

	mat res;
	for(int i = 0; i < x; ++i) res.s[i][i] = 1;

	while(b) {
		if(b & 1) res = res * q;
		q = q * q;
		b >>= 1;
	}

	cout << res.s[0][k] << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

