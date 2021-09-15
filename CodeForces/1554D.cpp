#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << (n == 1 ? "u" : (string(n / 2, 'u') + (n % 2 ? "wo" : "w") + string(n / 2 - 1, 'u'))) << endl;
	}
}
