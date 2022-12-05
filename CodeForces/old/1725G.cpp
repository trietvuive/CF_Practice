#include<bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	if(n <= 3) cout << 2*n+1 << endl;
	else {
		n -= 4;
		int start = (n/3 + 2) * 4;
		if(n % 3 == 0) cout << start << endl;
		else if(n % 3 == 1) cout << start + 1 << endl;
		else cout << start + 3 << endl;
	}
}
