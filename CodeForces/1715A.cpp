#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--) {
		int n,m; cin >> n >> m;
		--n, --m;
		if(n <= 1 && m <= 1)
			cout << ((n+m)*2) << "\n";
		else
			cout << (n + m + min(n,m) + 1) << "\n";
	}
}
