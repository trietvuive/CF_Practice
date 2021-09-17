#include<bits/stdc++.h>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc-- > 0)
	{
		int n; cin >> n;
		int last_xor = 0;
		for (int i = 1; i <= n; ++i)
		{
			int x; cin >> x;
			int y = (x ^ last_xor) & last_xor;
			//remember that xor 1 will flip bit, xor 0 will leave bit alone
			//we simply need to find bit that was turned on in last_xor but not in x
			//those bit need to be on in xor to flip x on. for other cases, there's no need to flip anything
			//that way we can turn the least bit possible, and our xor will be the smallest
			//ex: x = 1101, last_xor = 111, y = 10 to flip the second bit in x on
			last_xor = x ^ y;
			cout << y << " ";
		}
		cout << endl;
	}
}