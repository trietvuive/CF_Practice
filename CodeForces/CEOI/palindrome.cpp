#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

constexpr uint64_t MAXLEN = 1000005;
constexpr uint64_t mod = (1ULL << 61) - 1;

const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (mod / 3) + (mod / 3);

uint64_t base_pow[MAXLEN];

int64_t modmul(uint64_t a, uint64_t b){
    uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & mod) + (ret >> 61);
    ret = (ret & mod) + (ret >> 61);
    return ret - 1;
}

void init(){
    base_pow[0] = 1;
    for (int i = 1; i < MAXLEN; i++){
        base_pow[i] = modmul(base_pow[i - 1], base);
    }
}

int slow(string& s) {
	int n = s.length();
	int ans = 0;
	int l = 0;
	int r = s.length() - 1;

	string left = "";
	string right = "";
	bool middle = false;
	bool even_middle = false;

	while (l <= r) {
		left += s[l];
		right = s[r] + right;
		
		if (left == right) {
			ans += 2;
			left = "";
			right = "";
			if (l == r) {
				middle = true;
			}

			if (n % 2 == 0 && l + 1 == r) {
				even_middle = true;
			}
		}

		++l;
		--r;
	}

	if (n % 2 == 1) {
		if (middle) --ans;
		else ++ans;
	} else {
		if (!even_middle) ++ans;
	}

	return ans;
}

struct PolyHash{
    /// Remove suff vector and usage if reverse hash is not required for more speed
    vector<int64_t> pref, suff;

    PolyHash() {}

    template <typename T>
    PolyHash(const vector<T>& ar){
        if (!base_pow[0]) init();

        int n = ar.size();
        assert(n < MAXLEN);
        pref.resize(n + 3, 0), suff.resize(n + 3, 0);

        for (int i = 1; i <= n; i++){
            pref[i] = modmul(pref[i - 1], base) + ar[i - 1] + 997;
            if (pref[i] >= mod) pref[i] -= mod;
        }

        for (int i = n; i >= 1; i--){
            suff[i] = modmul(suff[i + 1], base) + ar[i - 1] + 997;
            if (suff[i] >= mod) suff[i] -= mod;
        }
    }

    PolyHash(const char* str)
        : PolyHash(vector<char> (str, str + strlen(str))) {}

    uint64_t get_hash(int l, int r){
        int64_t h = pref[r + 1] - modmul(base_pow[r - l + 1], pref[l]);
        return h < 0 ? h + mod : h;
    }

    uint64_t rev_hash(int l, int r){
        int64_t h = suff[l + 1] - modmul(base_pow[r - l + 1], suff[r + 2]);
        return h < 0 ? h + mod : h;
    }
};

void solve() {
	string s;
	cin >> s;
	int n = s.length();

	PolyHash hash_s(s.c_str());
	bool middle = false;
	bool even_middle = false;
	int l = 0, r = n - 1;
	int lp = 0, rp = n - 1;
	int ans = 0;

	while (l <= r) {
		if (hash_s.get_hash(lp, l) == hash_s.get_hash(r, rp)) {
			ans += 2;

			if (l == r) {
				middle = true;
			}

			if (n % 2 == 0 && l + 1 == r) {
				even_middle = true;
			}

			lp = l + 1;
			rp = r - 1;
		}

		++l;
		--r;
	}

	if (n % 2 == 1) {
		if (middle) --ans;
		else ++ans;
	} else {
		if (!even_middle) ++ans;
	}

	cout << ans << '\n';
	/* cout << slow(s) << '\n'; */
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

