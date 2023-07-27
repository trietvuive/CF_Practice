#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

ll ans[2000005], rows[2000005];

void solve() {
	int idx; cin >> idx; 
	cout << ans[idx] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);

	ans[1] = 1;
	ll index = 2;

	for(ll row = 2; row <= 2023 && index <= 1e6; ++row) {
		ans[index] = index * index + ans[index - row + 1];
		rows[index] = row;
		++index;
		
		for(ll col = 1; col < row-1; ++col, ++index)
			ans[index] = index * index + ans[index - row + 1]
										+ ans[index - row]
										- ans[index - 2*(row-1)],
			rows[index] = row;
		
		ans[index] = index * index + ans[index - row];
		rows[index] = row;
		++index;
	}

	int tc; cin >> tc;
	while(tc--) solve();
}

