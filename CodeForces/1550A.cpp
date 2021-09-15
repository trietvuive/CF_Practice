#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc; cin >> tc;
	while (tc --> 0) {
		int n; cin >> n;
		int sq = sqrt(n);
		if (sq * sq == n)cout << sq << endl;
		else cout << sq + 1 << endl;
	}
}
