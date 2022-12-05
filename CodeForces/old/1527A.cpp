#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int tc; cin >> tc;
	while (tc-- > 0)
	{
		int n; cin >> n;
		int a = 1;
		while (a * 2 <= n)
			a *= 2;
		cout << a - 1 << endl;
	}
}