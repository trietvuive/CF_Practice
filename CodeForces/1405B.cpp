#include<bits/stdc++.h>
using namespace std;
int x[102], y[102], tc, i, j;
int main() {
	for (cin >> tc; tc--;)
	{
		int n, k; cin >> n >> k;
		for (int i = 0; i < n; ++i)
			cin >> x[i] >> y[i];
		bool flag = false;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) 
				if (i != j && abs(x[i] - x[j]) + abs(y[i] - y[j]) > k)break;
			if (j == n) flag = true;
		}
		cout << (flag ? 1 : -1) << endl;

	}
}