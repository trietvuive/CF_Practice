#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int a, b, c; cin >> a >> b >> c;
		if((a == b and c%2 == 0) or (a == c and b % 2 == 0) or (b == c and a % 2 == 0)
			or a == b + c or b == a + c or c == a + b)
			cout << "yES\n";
		else
			cout << "nO\n";
	}
}