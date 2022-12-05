#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		int a, b, c; cin >> a >> b >> c;
		int supposed_a = 2 * b - c,
			supposed_b = (a + c) / 2,
			supposed_c = 2 * b - a;
		if (supposed_a >= a and supposed_a % a == 0)
			cout << "YES\n";
		else if ((a + c) % 2 == 0 and supposed_b >= b and supposed_b % b == 0)
			cout << "YES\n";
		else if (supposed_c >= c and supposed_c % c == 0)
			cout << "YES\n";
		else
			cout << "NO\n";

	}
}