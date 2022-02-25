#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, q; cin >> n >> q;
	string s; cin >> s;
	int sub_count = 0;
	for (int i = 0; i < (int)s.size() - 2; ++i)
		if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')++sub_count;

	for (int i = 0; i < q; ++i)
	{
		int idx; char c; cin >> idx >> c;
		--idx;
		int prev_sub = 0, new_sub = 0;
		for (int i = max(idx - 2, 0); i < min((int)s.size() - 2, idx+1); ++i)
			if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')++prev_sub;
		s[idx] = c;
		for (int i = max(idx - 2, 0); i < min((int)s.size() - 2, idx+1); ++i)
			if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')++new_sub;
		sub_count += new_sub - prev_sub;
		cout << sub_count << endl;
	}
}