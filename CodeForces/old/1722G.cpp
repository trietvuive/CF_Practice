#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	int last = 0;
	for(int i = 1; i <= n-3; ++i) cout << i << ' ', last ^= i;
	int third_last = n-2 + (1 << 29), second_last = n-1 + (1 << 30);
	cout << third_last << ' ' << second_last << ' ';
	last ^= third_last ^ second_last;
	cout << last << '\n';
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int tc; cin >> tc;
	while(tc--) 
		solve();
}
