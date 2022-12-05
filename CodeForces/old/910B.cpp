#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, a, b, a_cnt = 4, b_cnt = 2;
	cin >> n >> a >> b;
	int cnt = 0, len = n;
	while (a_cnt || b_cnt)
	{
		if ((len < a || !a_cnt) && (len < b || !b_cnt))
			len = n, ++cnt;
		if ((a_cnt > b_cnt && len >= a) || len < b)
			len -= a, --a_cnt;
		else
			len -= b, --b_cnt;
	}
	cout << cnt + 1 << endl;
}