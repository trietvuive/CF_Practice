#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m, rb, cb, rd, cd;
		cin >> n >> m >> rb >> cb >> rd >> cd;
		int tr = rd >= rb ? rd - rb : rb - rd + 2 * (n - rb);
		int tc = cd >= cb ? cd - cb : cb - cd + 2 * (m - cb);
		cout << min(tr, tc) << endl;
	}
}