#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	while (cases--)
	{
		int n, m, res = 0;
		cin >> n >> m;
		vector<int>mod_map(m, 0);
		for (int i = 0; i < n; i++)
		{
			int index;
			cin >> index;
			mod_map[index % m]++;
		}
		for (int i = 0; i < m; i++)
		{
			if (i == 0)
			{
				if (mod_map[0])
					res++;
			}
			else
			{
				int diff = abs(mod_map[i] - mod_map[m - i]);
				if (mod_map[i] && mod_map[m - i])
				{
					res++;
					if (diff > 0)diff--;
				}
				res += diff;
				mod_map[i] = 0;
				mod_map[m - i] = 0;
			}
		}
		cout << res << endl;
	}
}
