#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 2;
int ar[MAX_N], l = -1e9, r = 1e9, n;
string b;
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> ar[i];
	cin >> b;
	for (int i = 1; i < n; ++i)
		if (b[i] == '1' && b[i - 1] == '0')
			l = max(l, *max_element(ar + i - 4, ar + i + 1) + 1);
		else if(b[i] == '0' && b[i-1] == '1')
			r = min(r, *min_element(ar + i - 4, ar + i + 1) - 1);
	cout << l << " " << r << endl;
}