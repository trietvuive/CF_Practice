#include<bits/stdc++.h>
using namespace std;
int ar[502];
int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		int n, left, right;
		cin >> n; 
		left = n, right = n;
		for (int i = 1; i <= n; ++i)
			cin >> ar[i], left = min(left, (ar[i] != i ? i : n));

		for (int i = left+1; i <= n; ++i)
			if (ar[i] == left)
				right = i;

		reverse(ar + left, ar + right + 1);
		for (int i = 1; i <= n; ++i)
			cout << ar[i] << ' ';
		cout << endl;
	}
}