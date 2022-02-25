#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		int n; cin >> n;
		ll power = 0, sum = 0;
		ll max_element = 0;
		for (int i = 0; i < n; ++i)
		{
			ll number; cin >> number;
			while (number % 2 == 0)
				++power, number /= 2;
			sum += number, max_element = max(max_element, number);
		}

		cout << sum - max_element + (max_element << power) << endl;

	}
}