#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 2;
int ar[MAX_N];

bool palin_skip(int left, int right, int skip)
{
	while (left < right)
	{
		if (ar[left] == ar[right])++left, --right;
		else if (ar[left] == skip) ++left;
		else if (ar[right] == skip) --right;
		else return false;
	}
	return true;
}

int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		int n; cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> ar[i];
		int left = 0, right = n - 1;
		while (left < right && ar[left] == ar[right])
			++left, --right;
		if (palin_skip(left, right, ar[left]) || palin_skip(left, right, ar[right]))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}