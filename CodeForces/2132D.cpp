#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int> >;

vector<ll> digit_cnt, digit_sum, single_sum;

void pre_solve() {
  ll single_sm = 0;
  for(int i = 0; i <= 9; ++i) single_sum.push_back(single_sm += i);

  ll sm = 45, cnt_power = 9, sm_power = 10;
  digit_cnt.push_back(0); digit_cnt.push_back(9);
  digit_sum.push_back(0); digit_sum.push_back(sm);

  for(int digit = 2; digit <= 17; ++digit) {
    cnt_power *= 10;
    digit_cnt.push_back(digit_cnt.back() + digit * cnt_power);
    digit_sum.push_back(digit_sum.back() * 10 + sm * sm_power);
    sm_power *= 10;
  }
}

pair<ll, ll> find_cutoff(ll k) {
  int digit = 1;
  while(digit+1 < digit_cnt.size() && digit_cnt[digit+1] < k) ++digit;
  k -= digit_cnt[digit];
  ll cutoff = pow(10, digit) - 1 + (k / (digit + 1));
  ll remainder = k % (digit + 1);
  return std::make_pair(cutoff, remainder);
}

ll sum_partial_remainder(ll number, ll digit) {
  auto s = to_string(number);
  ll res = 0;
  for(int i = 0; i < digit; ++i)
    res += s[i] - '0';
  return res;
}

ll sum_infinite_digits(ll cutoff) {
  if(cutoff < 10) return single_sum[cutoff];
  ll sum_power = 10, digit = 1, sm = 0;
  while(sum_power * 10 <= cutoff) {
    sum_power *= 10;
    ++digit;
  }

  ll leading_digit = cutoff / sum_power;
  sm += digit_sum[digit] * leading_digit + single_sum[leading_digit - 1] * sum_power;
  sm += leading_digit * (cutoff % sum_power + 1);
  sm += sum_infinite_digits(cutoff % sum_power);
  return sm;
}

void solve() {
	ll n; cin >> n;
  if(n < 10) {
    cout << single_sum[n] << "\n";
    return;
  }

  auto [cutoff, remainder] = find_cutoff(n);
  ll ans = sum_partial_remainder(cutoff + 1, remainder) + sum_infinite_digits(cutoff);
  cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
  pre_solve();
	int tc = 1; cin >> tc;
	while(tc--) solve();
}

