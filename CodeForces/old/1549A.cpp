#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc; 
	cin >> tc;
	while (tc-- > 0)
	{
		int n; cin >> n;
		cout << 2 << " " << ( n == 5 ? 4 : (n - 1) / 2) << endl;
	}
}
