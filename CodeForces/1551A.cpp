#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n; cin >> n;
		cout << (n/3 + (n % 3 == 1)) <<  " " << (n/3 + (n % 3 == 2)) << endl;
	}
}
