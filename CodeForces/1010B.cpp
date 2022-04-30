#include<bits/stdc++.h>
using namespace std;
int n, p[32], r, e, l = 1, idx, mid;

int main() {
	cin >> r >> n;
	for (int i = 0; i < n; ++i)
	{
		cout << 1 << endl;
		cin >> e;
		if (e == 0)
			return 0;
		p[i] = e == -1 ? 0 : 1;
	}

	while (l <= r) {
		mid = (l + r) / 2;
		cout << mid << endl;
		cin >> e;
		if (e == 0) return 0;

		e = e == -1 ? 0 : 1;
		// if e == 0 and it's telling the truth
		// or e == 1 and it's lying
		if (e ^ p[idx++])
			r = mid - 1;
		else
			l = mid + 1;
		idx %= n;
	}
}