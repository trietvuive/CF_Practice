#include<bits/stdc++.h>
using namespace std;

int a[102];
int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n, k, cnt = 0; cin >> n >> k;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		for(int i = 1; i <= k; ++i) if(a[i] > k) ++cnt;
		cout << cnt << endl;
	}
}
