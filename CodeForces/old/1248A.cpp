#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		int n, m, element;
		ll no = 0, ne = 0, mo = 0, me = 0;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> element, no += element % 2, ne += element % 2 == 0;
		cin >> m;
		for (int i = 0; i < m; ++i)
			cin >> element, mo += element % 2, me += element % 2 == 0;

		cout << no * mo + ne * me << endl;
	}
}