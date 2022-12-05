#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 4e5 + 5;
vector<int> divisor[N];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	int tc; cin >> tc;
	for(int i = 1; i < N; ++i)
		for(int j = 2*i; j < N; j += i)
			divisor[j].push_back(i);
	
	while(tc--) {
		ll l,r; cin >> l >> r;
		ll len = (r-l+1), ans = (len * (len-1) * (len-2)) / 6ll;

		for(int k = l+2; k <= r; ++k) {
			int k_twice = 2*k;
			for(int i_idx = 0; i_idx < divisor[k_twice].size(); ++i_idx) {
				int i = divisor[k_twice][i_idx];
				if(i < l) continue;
				if(i >= k) break;
				for(int j_idx = i_idx + 1; j_idx < divisor[k_twice].size(); ++j_idx) {
					int j = divisor[k_twice][j_idx];
					if(j < l) continue;
					if(j >= k) break;
					if((k % i == 0 && k % j == 0) || (i + j) > k) {
						--ans;
					}
				}
			}
		}
		cout << ans << "\n";
	}
}
