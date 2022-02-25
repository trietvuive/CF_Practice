#include<bits/stdc++.h>
using namespace std;

int ar[10002];
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n; cin >> n;
		int max_val = INT_MIN, min_val = INT_MAX;
		for (int i = 0; i < n; ++i)
		{
			int element; cin >> element;
			max_val = max(max_val, element), min_val = min(min_val, element);
		}
		cout << max_val - min_val << endl;
	}
}