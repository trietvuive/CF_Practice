#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc --> 0)
	{
		int l, r; cin >> l >> r;
		cout << r % max(l, r / 2 + 1) << endl;
	}
}