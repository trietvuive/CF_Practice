#include<bits/stdc++.h>
using namespace std;
int cnt[26];
int main()
{
	int n; 
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		cout << s << endl;
	}
}