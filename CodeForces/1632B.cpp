#include<bits/stdc++.h>
using namespace std;
int lg(int n)
{
	if (n == 1) return 0;
	return lg(n >> 1) + 1;
}
int main()
{
	int tc; cin >> tc;
	while (tc-- > 0)
	{
		int n; cin >> n;
		for (int i = n - 1; i >= 1 << lg(n - 1); --i)
			cout << i << ' ';
		for (int i = 0; i < 1 << lg(n - 1); ++i)
			cout << i << ' ';
		cout << endl;
	}
}