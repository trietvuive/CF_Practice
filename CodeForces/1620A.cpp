#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	while (n--)
	{
		string s; cin >> s;
		int cnt = 0;
		for (int i = 0; i < s.size() - 1; ++i)
			cnt += s[i] == 'N';
		if ((s[s.size() - 1] == 'E' && cnt == 1) || 
			(s[s.size() - 1] == 'N' && cnt == 0))
			cout << "NO\n";
		else cout << "YES\n";
	}
}