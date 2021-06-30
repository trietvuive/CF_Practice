/*#include <iostream>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	while (cases--)
	{
		int n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;
		if ((b == n) + (d == n) > min(a, c) || (a == n) + (c == n) > min(b, d) ||
			2 * (b == n) + (b == n - 1) + 2 * (d == n) + (d == n - 1) > a + c ||
			2 * (a == n) + (a == n - 1) + 2 * (c == n) + (c == n - 1) > b + d)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}
*/