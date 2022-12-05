#include<bits/stdc++.h>
using namespace std;
vector<int>dp(24002);
int main() {
	int G, N;
	cin >> G >> N;
	vector<pair<int, int>> calendar;
	for (int i = 0; i < N; ++i)
	{
		int start, end;
		cin >> start >> end;
		calendar.push_back({start,end});
	}
	sort(calendar.begin(), calendar.end(), [](auto& a, auto& b) -> bool {return a.second < b.second; });
	int pointer = 0;
	int mx = 1;
	int r1 = calendar[0].second;
	for (int i = 1; i < calendar.size(); ++i)
	{
		int l1 = calendar[i].first;
		int r2 = calendar[i].second;
		if (l1 >= r1)
			++mx, r1 = r2;
	}
	if (mx >= G)cout << "YES" << endl;
	else cout << "NO" << endl;
}