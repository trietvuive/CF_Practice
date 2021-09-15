#include<bits/stdc++.h>
using namespace std;
int a[1002];
int main() {
	int start = 1;
	for (int i = 0; i < 1002; ++i,++start)
	{
		while (start % 10 == 3 || start % 3 == 0)++start;
		a[i] = start;
	}
	int t;
	cin >> t;
	while (t--)
	{
		int k; cin >> k;
		cout << a[k - 1] << endl;
	}
}
