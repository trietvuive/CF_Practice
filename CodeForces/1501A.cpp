#include<vector>
#include<iostream>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		int station_cnt;
		cin >> station_cnt;
		vector<pair<int, int>> stations;
		stations.push_back({ 0,0 });
		for (int i = 0; i < station_cnt; i++)
		{
			int arrival, depart;
			cin >> arrival >> depart;
			stations.push_back({ arrival,depart });
		}
		vector<int> delays;
		for (int i = 0; i < station_cnt; i++)
		{
			int delay;
			cin >> delay;
			delays.push_back(delay);
		}
		int ans = 0;
		for (int i = 1; i <= station_cnt; i++)
		{
			ans += stations[i].first - stations[i - 1].second + delays[i - 1];
			if(i!=station_cnt)
				ans = max(stations[i].second, ans + (stations[i].second - stations[i].first + 1)/2);
		}
		cout << ans << endl;
	}
}
