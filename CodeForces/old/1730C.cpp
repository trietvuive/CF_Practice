#include<iostream>
#include<map>
#include<vector>
#include<stack>

using namespace std;

void solve() {
	string s; cin >> s;
	string ans;
	vector<int> cnt(11, 0);
	vector<int> last_idx(10, -1);
	int cur_char = 0;
	for(int i = 0; i < s.size(); ++i)
		last_idx[s[i] - '0'] = i;
	last_idx[9] = INT_MAX;
	for(int i = 0; i < s.size(); ++i) {
	
		while(last_idx[cur_char] < i) {
			if(cnt[cur_char] > 0) {
				ans += string(cnt[cur_char], cur_char + '0');
			}
			++cur_char;
		}

		int c = s[i] - '0';
		if(c != cur_char) 
			cnt[min(9,c+1)]++;
		else
			cnt[c]++;

		if(i == last_idx[cur_char]) 
			ans += string(cnt[cur_char], cur_char + '0'), ++cur_char;

	}

	while(cur_char < 10) 
		ans += string(cnt[cur_char], cur_char + '0'), ++cur_char;
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}
