#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc --> 0)
	{
		int n, k;
		cin >> n >> k;
		vector<pair<int, int>> ar;
		for (int i = 0; i < n; ++i)
		{
			int element; cin >> element;
			ar.push_back({ element, i });
		}
		sort(ar.begin(), ar.end());
		for (int i = 1; i < n; ++i)
		{
			if (ar[i].second != ar[i - 1].second + 1)--k;
		}
		if (k >= 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}
