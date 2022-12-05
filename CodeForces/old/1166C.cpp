#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 2;
int ar[MAX_N];
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; ++i)cin >> ar[i], ar[i] = abs(ar[i]);
	sort(ar, ar + n);
	long long cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		int left = i, right = n - 1;
		while (left < right)
		{
			int mid = (left + right + 1) / 2;
			if (ar[mid] <= ar[i] * 2)
				left = mid;
			else
				right = mid - 1;
		}
		cnt += left - i;
	}
	cout << cnt << endl;
}