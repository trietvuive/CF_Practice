#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

constexpr ll MOD = 998244353;
stack<bool> st;

void S(ll p, ll q) {
	if(p == 1 && q == 1) return;

	// p = S(n+1, 2m+1), q = S(n+1, 2m+2) = S(n, m+1)
	// p = q + S(n,m), recurse to (p-q, q)
	// k = 2 * S(p-q, q) + 1 
	if(p > q) {
		st.push(true);
		S(p-q, q);
	}

	// q = S(n+1, 2*k+1), p = S(n+1, 2*k) = S(n, k)
	// q = p + S(n,k+1), recurse to (p, q-p)
	// k = 2 * S(p, q-p)
	else {
		st.push(false);
		S(p, q-p);
	}
}

void solve() {
	ll p, q; cin >> p >> q;
	S(p, q);
	ll ans = 1;
	while(!st.empty()) {
		ans = (ans * 2 + st.top()) % MOD;
		st.pop();
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

