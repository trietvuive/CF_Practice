#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc-- > 0)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cout << ((a + b + c) % 3 ? 1 : 0) << endl;
	}
}