#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int k; cin >> k;
		int start_r = 1, start_c = ceil(sqrt(k));
		int start_num = (start_c - 1) * (start_c - 1) + 1;
		cout << min(start_c, k - start_num + 1) <<" " << (k >= start_num + start_c ? start_c * start_c - k + 1 : start_c) << endl;
	}
}
