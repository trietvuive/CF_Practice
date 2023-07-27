#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

int a[55];
void solve() {
	int n; cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a+n);

	if(a[0] == a[n-1]) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	for(int left = 0, right = n-1, flip = 0; left <= right; flip^= 1) {
		if(flip)
			cout << a[right--] << ' ';
		else
			cout << a[left++] << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc;
	cin >> tc;
	while(tc--) solve();
}

