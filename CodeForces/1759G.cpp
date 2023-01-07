#include<bits/stdc++.h>
using namespace std;
int ar[200005];

void solve() {
	int n; cin >> n;
	set<int> st;
	vector<bool> used(n+1, false);
	for (int i = 2; i <= n; i+=2) {
		cin >> ar[i];
		used[ar[i]] = true;
	}

	for(int i = 1; i <= n; i++) {
		if(!used[i]) {
			st.insert(i);
		}
	}
	if(st.size() != n/2) {
		cout << -1 << '\n';
		return;
	}

	for(int i = n; i >= 2; i -= 2) {
		int second = ar[i];
		auto iter = st.lower_bound(second);
		if(iter == st.begin()) {
			cout << -1 << '\n';
			return;
		}
		--iter;
		ar[i-1] = *iter;
		st.erase(iter);
	}
	for(int i = 1; i <= n; ++i) cout << ar[i] << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
}
