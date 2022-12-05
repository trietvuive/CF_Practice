#include<bits/stdc++.h>
using namespace std;

int main()
{
	int cases; 
	cin >> cases;
	while (cases--)
	{
		int n;
		cin >> n;
		int mn = 1e9 + 2, index = -1;
		for (int i = 1; i <= n; ++i)
		{
			int element;
			cin >> element;
			if (element < mn) mn = element, index = i;
		}
		cout << n - 1 << endl;
		for (int i = index + 1; i <= n; ++i)
			cout << index << " " << i << " " << mn << " " << (i - index) % 2 + mn << endl;
		for (int i = index - 1; i >= 1; --i)
			cout << index << " " << i << " " << mn << " " << (index - i) % 2 + mn << endl;

	}
}
