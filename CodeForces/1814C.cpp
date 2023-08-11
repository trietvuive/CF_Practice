#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void print_vector(const vector<int>& v) {
	cout << v.size() << ' ';
	for(int i : v) cout << i << ' ';
	cout << '\n';
}
void solve() {
	int n, s1, s2, element; cin >> n >> s1 >> s2;
	vector<pii> v;

	for(int i = 1; i <= n; ++i)
		cin >> element, v.push_back({element, i});

	sort(v.begin(), v.end(), greater<pii>());

	vector<int> v1, v2;
	int t1 = s1, t2 = s2;

	for(const auto& [_, idx] : v) {
		if(t1 < t2 || (t1 == t2 && s1 < s2))
			v1.push_back(idx), t1 += s1;
		else
			v2.push_back(idx), t2 += s2;
	}
	print_vector(v1), print_vector(v2);
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

