#include<iostream>
using namespace std;
int star[52];
int main()
{
	int cases;
	cin >> cases;
	while (cases--)
	{
		int n, k, star_count = 0;
		cin >> n >> k;
		char c;
		for (int i = 0; i < n; i++)
		{
			cin >> c;
			if (c == '*')
				star[star_count++] = i;
		}
		int last_star = star[0];
		int count = 2;
		for (int i = 1; i < star_count - 1; i++)
		{
			if (star[i + 1] - last_star > k)
				count++, last_star = star[i];
		}
		cout << min(count,star_count) << endl;
	}
}
