#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc; cin >> tc;
	while (tc-- > 0)
	{
		int c, d;
		cin >> c >> d;
		if (c == 0 && d == 0)cout << 0 << endl;
		else if (c == d)cout << 1 << endl;
		else if ((c + d) % 2)cout << -1 << endl;
		else cout << 2 << endl;
	}
}
