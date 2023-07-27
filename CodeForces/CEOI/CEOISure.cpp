#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int N;
	cin >> N;

	vector<double> a(N), b(N);
	for(int i = 0; i < N; ++i)
		cin >> a[i] >> b[i];

	sort(a.begin(), a.end(), greater<>());
	sort(b.begin(), b.end(), greater<>());

	double ans = 0;
	int bets_taken = 0;

	int ap = 0, bp = 0;
	double a_sum = 0, b_sum = 0;

	for (int i = 0; i < 2 * N; ++i) {
		if (ap < N && bp < N) {
			if (a_sum < b_sum) {
				a_sum += a[ap++];
			} else {
				b_sum += b[bp++];
			}
		} else if (ap < N) {
			a_sum += a[ap++];
		} else if (bp < N) {
			b_sum += b[bp++];
		} else {
			assert(0);
		}

		++bets_taken;
		ans = max(ans, min(a_sum, b_sum) - bets_taken);
	}
	cout << fixed << setprecision(4) << ans << endl;
}

