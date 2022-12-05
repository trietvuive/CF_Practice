#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m; cin >> n >> m;
		if (n == 1 && m == 1)
			cout << 0 << endl;
		else if (n != 1 && m != 1)
			cout << 2 << endl;
		else cout << 1 << endl;
	}
}