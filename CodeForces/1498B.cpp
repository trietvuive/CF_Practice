#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, W, ans = 0;
		cin >> n >> W;
		vector<int>count(31, 0);
		for (int i = 0; i < n; ++i)
		{
			int temp;
			cin >> temp;
			++count[log2(temp)];
		}
		while (n)
		{
			int temp = W;
			for (int i = 30; i >= 0; --i)
			{
				while (count[i])
					if (temp >= 1 << i)
						temp -= 1 << i, --n, --count[i];
					else
						break;
			}
			++ans;
		}
		cout << ans << endl;
	}
}
