#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 2e9;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<ll> temperatures(n+2,INF);
		vector<pair<int,ll>> conditioners;
		for (int i = 0; i < k; ++i)
		{
			int position; cin >> position;
			conditioners.push_back({ position,-1 });
		}
		for (int i = 0; i < k; ++i)
		{
			int temperature; cin >> temperature;
			conditioners[i].second = temperature;
		}
		sort(conditioners.begin(), conditioners.end());
		int pointer_forward = 0;
		ll min_temp = INF;
		for (int i = 1; i <= n; ++i)
		{
			if (pointer_forward < k && i == conditioners[pointer_forward].first)
				min_temp = min(min_temp, conditioners[pointer_forward].second), ++pointer_forward;
			temperatures[i] = min(temperatures[i], min_temp);
			++min_temp;
		}
		int pointer_backward = k - 1;
		min_temp = INF;
		for (int i = n; i >= 1; --i)
		{
			if (pointer_backward > -1 && i == conditioners[pointer_backward].first)
				min_temp = min(min_temp, conditioners[pointer_backward].second), --pointer_backward;
			temperatures[i] = min(temperatures[i], min_temp);
			++min_temp;
		}
		for (int i = 1; i <= n; ++i)
			cout << temperatures[i] << " ";
		cout << endl;
	}
}
