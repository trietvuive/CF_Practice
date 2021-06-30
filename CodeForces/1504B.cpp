/*#include<iostream>
using namespace std;
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n;
		string a, b;
		cin >> n >> a >> b;
		int sa = 0, sb = 0;
		bool good = true;
		for (int i = 0; i < n; i++)
		{
			sa += 2 * (a[i] - '0') - 1;
			sb += 2 * (b[i] - '0') - 1;
			good &= abs(sa) == abs(sb);
		}
		good &= sa == sb;
		cout << (good ? "YES" : "NO") << endl;
	}
}
*/