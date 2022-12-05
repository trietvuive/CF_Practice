#include<bits/stdc++.h>
using namespace std;

void solve() {
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);

	string s; cin >> s;
	for(int i = 0; i < 3; ++i) {
		if(s[i] == 'A') cout << a[0] << " ";
		else if(s[i] == 'B') cout << a[1] << " ";
		else cout << a[2] << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	solve();
}
