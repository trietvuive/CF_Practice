#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		string s; cin >> s;
		vector<ll> delta;
		ll initial_sum = 0;
		
		for(int i = 0; i < n; ++i) {
			int left = i, right = n-1-i;
			if(s[i] == 'L') {
				initial_sum += left;
				if(right > left) delta.push_back(right - left);
			}
			if(s[i] == 'R') {
				initial_sum += right;
				if(left > right) delta.push_back(left - right);
			}
		}

		sort(delta.begin(), delta.end(), greater<int>());
		for(int i = 0; i < n; ++i) {
			if(i < delta.size())
				initial_sum += delta[i];
			cout << initial_sum << ' ';
		}
		cout << '\n';
	}
}
