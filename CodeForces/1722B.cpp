#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	int tc, n;
	string a, b;
	cin >> tc;
	while(tc--) {
		cin >> n >> a >> b;
		bool ans = true;
		for(int i = 0; i < n; ++i)
			if(a[i] != b[i] && (a[i] == 'R' || b[i] == 'R')) {
				ans = false;
				break;
			}

		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}
}
