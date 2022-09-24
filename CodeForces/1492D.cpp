#include<bits/stdc++.h>
using namespace std;

void print(int a, int b, int k, bool larger) {
	cout << 1;
	if(k == 0) {
		cout << string(b, '1') << string(a, '0') << '\n';
		return;
	}
	int n = a + b;
	int switch_idx = n-1-k;
	--a, --b;
	for(int i = 0; i < n; ++i) {
		if(i == switch_idx) {
			if(larger) cout << '1';
			else cout << '0';
			continue;
		}
		else if(i == n-1) {
			if(larger) cout << '0';
			else cout << '1';
			continue;
		}
		else if(b-- > 0) cout << '1';
		else if(a-- > 0) cout << '0';
	}
	cout << '\n';
}
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int a,b,k; cin >> a >> b >> k;
	--b;
	if((a+b <= k || b == 0 || a == 0) && k) {
		cout << "NO\n";
		return 0;
	}
	else {
		cout << "YES\n";
		print(a, b, k, true);
		print(a, b, k, false);
	}
}
