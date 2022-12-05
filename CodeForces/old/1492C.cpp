#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int MAX = 10e5 + 2;
int ans = 0, n, m, left_ar[MAX], right_ar[MAX];
int main()
{
	string s, t;
	cin >> n >> m >> s >> t;
	for (int i = 0, j = 0; j < m; i++)
		if (s[i] == t[j])left_ar[j++] = i;
	for (int i = n - 1, j = m - 1; j >= 0; i--)
		if (s[i] == t[j])
			right_ar[j--] = i;
	for (int i = 1; i < m; i++)
		ans = max(ans, right_ar[i] - left_ar[i - 1]);
	cout << ans << endl;
}
