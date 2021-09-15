#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int first_1 = n+1;
		for (int i = 0; i < n; ++i)
		{
			int road; cin >> road; if(road == 1)first_1 = min(first_1, i);
		}
		for (int i = 0; i < n + 1; ++i)
		{
			cout << (i == first_1 ? n + 1 : i < first_1 ? i+1 : i) << " ";
		}
		cout << endl;
	}
}
