#include<bits/stdc++.h>

using namespace std;

int a[2005];
void solve() {
	int n,p; cin >> n >> p;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a,a+n);
	for(int i = 0; i < n; i++) {
		if(a[i] >= p) {
			cout << "NO\n";
			exit(0);
		}
		p += a[i];
	}
	cout << "YES\n";
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	solve();
}
