#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void print(int ans, const vector<int>& v) {
	cout << ans << '\n';
	for(int i : v) cout << i << ' ';
	cout << '\n';
}

int count_open(const string& s) {
	int ans = 0;
	for(char c : s) ans += c == '(';
	return ans;
}

bool balance(const string& s) {
	bool positive = s[0] == '(';
	int balance = 0;
	for(char c : s) {
		balance += (c == '(' ? 1 : -1);
		if((positive && balance < 0) ||
		   (!positive && balance > 0)) return false;
	}
	return true;
}

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	if(n % 2 || count_open(s) != n/2) {
		cout << -1 << '\n';
	} else if(balance(s)) {
		print(1, vector<int>(n, 1));
	} else {
		vector<int> v;
		for(int i = 0; i < n/2; ++i) 
			v.push_back(1 + (s[i] == ')'));
		for(int i = n/2; i < n; ++i)
			v.push_back(1 + (s[i] == '('));
		print(2, v);
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

