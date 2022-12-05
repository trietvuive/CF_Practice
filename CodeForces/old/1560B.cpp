#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int n = abs(a - b) * 2;
		if (n < a || n < b || n < c) cout << -1 << endl;
		else cout << (c > n / 2 ? c - n / 2 : c + n / 2) << endl;
	}
}
