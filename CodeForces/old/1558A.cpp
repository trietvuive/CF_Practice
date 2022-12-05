#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		if (a > b)swap(a, b);
		int min_break = (b - a) / 2, max_break = a + b - min_break;
		cout << (max_break - min_break) / (2 - ((a + b) & 1)) + 1 << endl;
		for (int i = min_break; i <= max_break; i += (2 - ((a + b) & 1)))
			cout << i << " ";
		cout << endl;
	}
}