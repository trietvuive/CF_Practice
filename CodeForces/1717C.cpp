#include<bits/stdc++.h>
using namespace std;

int a[200005], b[200005];
bool solve() {
	int n; cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) cin >> b[i];

	for(int i = 1; i <= n; ++i) {
		if(a[i] > b[i]) return false;
		int next = i == n ? b[1] : b[i+1];
		if(a[i] < b[i] && b[i] > next + 1) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int tc; cin >> tc;
	while(tc--) 
		if(solve()) cout << "YES\n";
		else cout << "NO\n";
}
