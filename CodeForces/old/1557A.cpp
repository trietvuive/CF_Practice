#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	cout.precision(6);
	while (t--)
	{
		int n;
		double sum = 0, largest = -2e9;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int a; cin >> a;
			sum += a;
			if (largest < a)largest = a;
		}
		printf("%.16lf\n", largest + (sum-largest)/(n-1));
	}
}
