#include<bits/stdc++.h>
using namespace std;

int countBits(int n) {
	int count = 0;
	while (n) n &= (n - 1), ++count;
	return count;
}
int digits(int x)
{
	int mask = 0;
	while (x > 0)mask |= (1 << x % 10), x /= 10;
	return countBits(mask);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		while (digits(n) > k)
		{
			int r = 1, l = n;
			while (digits(l) > k)l /= 10, r *= 10;
			r /= 10;
			n = ((n / r) + 1) * r;
		}
		cout << n << endl;
	}
}