#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int w, h, n;
	cin >> w >> h >> n;
	set<int> x, y;
	multiset<int> x_length, y_length;
	x.insert(0), x.insert(w);
	y.insert(0), y.insert(h);
	x_length.insert(w);
	y_length.insert(h);
	while (n--)
	{
		char c; cin >> c;
		int position; cin >> position;
		if (c == 'H')
		{
			auto iter = y.upper_bound(position);
			int after = *iter, before = *(--iter);
			int distance = after - before;
			y_length.erase(y_length.find(distance));
			y_length.insert(after - position), y_length.insert(position - before);
			y.insert(position);
		}
		else
		{
			auto iter = x.upper_bound(position);
			int after = *iter, before = *(--iter);
			int distance = after - before;
			x_length.erase(x_length.find(distance));
			x_length.insert(after - position), x_length.insert(position - before);
			x.insert(position);
		}
		ll max_x = (*x_length.rbegin()), max_y = (*y_length.rbegin());
		cout << max_x * max_y << endl;
	}
}