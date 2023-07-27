#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

int p[200005];
void solve() {
	int n; cin >> n;
	for(int i = 1; i <= n; ++i) {
		int x; cin >> x;
		p[x] = i;
	}
	p[0] = 0, p[n+1] = n+1;

	int left = n/2 + (n&1), right = n/2 + 1;
	int left_idx = p[left], right_idx = p[right];
	if(left_idx > right_idx) {
		cout << left << '\n';
		return;
	}

	while(left > 1 && right < n) {
		if(p[left-1] > left_idx) break;
		if(p[right+1] < right_idx) break;
		if(p[right+1] < p[left-1]) break;

		left_idx = p[--left];
		right_idx = p[++right];
	}

	cout << left - 1 << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

