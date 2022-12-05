#include<bits/stdc++.h>
using namespace std;

int main() {
	ofstream out_file;
	ifstream in_file;
	out_file.open("text/output.txt");
	in_file.open("text/input.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	in_file >> tc;
	for(int i = 1; i <= tc;++i)
	{
		vector<int>cnt(27, 0);
		string s;
		in_file >> s;
		for (char i : s)++cnt[i - 'A'];
		int total_vow = 0, total_con = 0, max_vow = 0, max_con = 0;
		for (char c = 'A'; c <= 'Z'; ++c)
		{
			if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
				total_vow += cnt[c-'A'], max_vow = max(max_vow, cnt[c - 'A']);
			else
				total_con += cnt[c-'A'], max_con = max(max_con, cnt[c - 'A']);
		}
		int ans = min(total_con + (total_vow - max_vow) * 2, total_vow + (total_con - max_con) * 2);
		out_file << "Case #" << i << ": " << ans << endl;
	}
	out_file.close();
}