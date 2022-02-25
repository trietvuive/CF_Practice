#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 2;

int ans[MAX_N * 2], input[MAX_N];

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, mx = 0;; cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> input[i], mx = max(mx, input[i]);
		int left = 0, right = n - 1, left_ptr = n, right_ptr = n + 1;
		if (input[left] != mx && input[right] != mx)
		{
			cout << -1 << endl;
			continue;
		}

		while (left <= right)
		{
			if (input[right] > input[left])
				ans[right_ptr++] = input[right--];
			else
				ans[left_ptr--] = input[left++];
		}
		for (int i = left_ptr + 1; i < right_ptr; ++i)
			cout << ans[i] << " ";
		cout << endl;


	}
}