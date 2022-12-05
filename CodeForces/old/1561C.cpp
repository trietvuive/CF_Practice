#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin >> tc;
	while (tc-- > 0)
	{
		vector<pair<int, int>> vec;
		int caves;
		cin >> caves;

		for (int i = 0; i < caves; ++i)
		{
			int monsters; cin >> monsters;
			int min_power = 0;
			for (int j = 0; j < monsters; ++j)
			{
				int monster; cin >> monster;
				min_power = max(min_power, monster - j + 1);
			}
			vec.push_back({ min_power, monsters });
		}
		sort(vec.begin(), vec.end());
		int monsters_encountered = 0;
		int ans = 0;
		for (int i = 0; i < vec.size(); ++i) {
			ans = max(ans, vec[i].first - monsters_encountered);
			monsters_encountered += vec[i].second;
		}
		cout << ans << endl;
	}
}