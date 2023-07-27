#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int left = 0, right = n-1;
	while(left < right && s[left] != s[right]) left++, right--;

	cout << max(0, right-left+1) << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

