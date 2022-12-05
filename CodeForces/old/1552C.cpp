#include<bits/stdc++.h>
using namespace std;
bool overlap(const pair<int, int>& a, const pair<int, int>& b)
{
	//return (a.first < b.first && a.second < b.second) || (a.first > b.first && a.second > b.second) ? true : false;
	if (a.first < b.first && b.first < a.second && a.second < b.second)
		return true;
	if (b.first < a.first && a.first < b.second && b.second < a.second)
		return true;
	return false;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;

		vector<pair<int, int>> chords;
		vector<int> remaining_point;
		vector<bool> used(2 * n + 1, false);
		for (int i = 0; i < k; ++i)
		{
			int a, b;
			cin >> a >> b;
			if (a > b)swap(a, b);
			chords.push_back({ a,b });
			used[a] = true, used[b] = true;
		}
		for (int i = 1; i <= 2 * n; ++i)
			if (!used[i])
				remaining_point.push_back(i);
		for (int i = 0; i < remaining_point.size() / 2; ++i)
			chords.push_back({ remaining_point[i], remaining_point[i + remaining_point.size() / 2] });
		int count = 0;
		for (int i = 0; i < chords.size(); ++i)
			for (int j = i + 1; j < chords.size(); ++j)
				count += overlap(chords[i], chords[j]);
		cout << count << endl;
	}
}
