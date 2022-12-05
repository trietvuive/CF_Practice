#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int tc; cin >> tc;
	while(tc--) {
		int n,m; cin >> n >> m;
		if(n > m || (n % 2 == 0 && m % 2 == 1)) cout << "No\n";
		else {
			cout << "Yes\n";
			int last = n % 2 ? n-1 : n-2;
			for(int i = 1; i <= last; ++i) cout << "1 ";
			n -= last, m -= last;
			if(n == 2) cout << m/2 << ' ' << m/2 << '\n';
			else cout << m << '\n';
		}
	}
}
