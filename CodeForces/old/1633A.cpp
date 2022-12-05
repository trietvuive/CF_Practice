#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc; cin >> tc;
	while (tc-- > 0)
	{
		int n; cin >> n;
		int l = n % 10, m = n % 7;
		cout << (l >= m ? n - m : n + 7 - m) << endl;
	}
}