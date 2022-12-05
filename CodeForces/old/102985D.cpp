#include<vector>
#include<iostream>
#include<algorithm>
#define ll long long

using namespace std;
const int MAX = 10e3 + 2;
const int MAX_N = 10e9 + 2;
int main()
{
	int l, h, w, v;
	cin >> l >> h >> w >> v;
	vector<pair<ll, ll>> vec;
	vector<ll>horizontal_cut(w+1), vertical_cut(v+1);
	horizontal_cut.push_back(0);
	vertical_cut.push_back(0);
	for (int i = 1; i <= w; i++)
	{
		cin >> horizontal_cut[i];
	}
	for (int i = 1; i <= v; i++)
	{
		cin >> vertical_cut[i];
	}
	horizontal_cut[w + 1] = l;
	vertical_cut[v + 1] = h;
	sort(horizontal_cut.begin(), horizontal_cut.end());
	sort(vertical_cut.begin(), vertical_cut.end());
	for (int i = 0; i < w+1; i++)
	{
		for (int j = 0; j < v+1; j++)
		{
			ll id_left = horizontal_cut[i] * MAX_N + vertical_cut[j];
			ll length = (horizontal_cut[i + 1] - horizontal_cut[i]) * MAX_N +
				(vertical_cut[j + 1] - vertical_cut[j]);
			vec.push_back({id_left,length});
		}
	}
	sort(vec.begin(), vec.end(), [](const pair<ll, ll>& lhs, const pair<ll, ll>& rhs)
		{
			ll area_diff = (lhs.second / MAX_N) * (lhs.second % MAX_N) - (rhs.second / MAX_N) * (rhs.second % MAX_N);
			return area_diff ? area_diff > 0 : lhs.first < rhs.first;
		});
	pair<ll, ll> res = *vec.begin();
	ll left_x = res.first / MAX_N;
	ll left_y = res.first % MAX_N;
	std::cout << left_y <<" " << left_x <<" "<< left_y + res.second % MAX_N<<" "<< left_x + res.second / MAX_N;
}