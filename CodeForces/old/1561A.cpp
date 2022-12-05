#include<bits/stdc++.h>
using namespace std;
int ar[1005];
int main() {
	int tc;
	cin >> tc;
	while (tc-- > 0)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)cin >> ar[i];
		int iter = 1;
		while (!is_sorted(ar, ar + n))
		{
			if (iter % 2) {
				for (int i = 0; i <= n - 3; i += 2)
					if (ar[i] > ar[i + 1])swap(ar[i], ar[i + 1]);
			}
			else
				for (int i = 1; i <= n - 2; i += 2)
					if (ar[i] > ar[i + 1])swap(ar[i], ar[i + 1]);
			++iter;
		}
		cout << iter - 1 << endl;
	}
}