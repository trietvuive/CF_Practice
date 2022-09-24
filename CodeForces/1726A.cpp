#include<bits/stdc++.h>
using namespace std;

int ar[2005];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		for(int i = 0; i < n; ++i) cin >> ar[i];

		int mx = 0;
		for(int i = 0; i < n; ++i) {
			mx = max(mx, ar[i] - ar[(i+1) % n]);
			mx = max(mx, ar[i] - ar[0]);
			mx = max(mx, ar[n-1] - ar[i]);
		}
		
		cout << mx << '\n';
	}
}
