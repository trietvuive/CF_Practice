#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		cout << n << ' ';
		for(int i = 2; i <= n; ++i) cout << i-1 << ' ';
		cout << endl;
	}
}
