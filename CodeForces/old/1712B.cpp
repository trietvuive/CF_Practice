#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		int even = 2, odd = 1, even_first = 0;
		if(n % 2) cout << 1 << ' ', even_first = 0, odd = 3;
		else even_first = 1;
		while(even <= n && odd <= n) {
			if(even_first) cout << even << ' ' << odd << ' ';
			else cout << odd << ' ' << even << ' ';
			odd += 2, even += 2;
		}
		cout << endl;
	}
}
