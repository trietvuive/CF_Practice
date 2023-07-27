#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;


void solve() {
	int n, m; cin >> n >> m;
	string a, b; cin >> a >> b;
	reverse(b.begin(), b.end());
	a += b;

	int largest = 1, curr = 1;
	for(int i = 1; i < a.size(); ++i) {
		if(a[i] == a[i-1]) ++curr;
		else curr = 1;

		if(largest > 1 && curr > 1) {
			cout << "NO" << endl;
			return;
		}

		largest = max(largest, curr);
		if(largest > 2) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

