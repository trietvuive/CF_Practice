#include<bits/stdc++.h>
using namespace std;
int ans, n, idx, cumulative;
string s;


void solve() {
	cin >> n >> s;
	for(int i = 0; i < s.size() -1; ++i)
		if(s[i] == ')' && s[i+1] == '(') --n;
	cout << n << '\n';
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int tc; cin >> tc;
	while(tc--) solve();
}
