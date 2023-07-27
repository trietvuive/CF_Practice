#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

int sum_of_digit(int x) {
	int res = 0;
	while (x > 0) {
		res += x % 10;
		x /= 10;
	}
	return res;
}

void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n+1);
	set<int> idx;
	for (int i = 1; i <= n; i++) cin >> a[i], idx.insert(i);

	for(int i = 0; i < q; ++i) {
		int query; cin >> query;
		if(query == 1) {
			int l,r; cin >> l >> r;
			for(auto iter = idx.lower_bound(l); iter != idx.end() && *iter <= r;) {
				int index = *iter;
				a[index] = sum_of_digit(a[index]);
				if(a[index] < 10) idx.erase(iter++);
				else iter++;
			}
		}
		else {
			int x; cin >> x;
			cout << a[x] << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

