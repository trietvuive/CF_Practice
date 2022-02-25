#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mn = LLONG_MAX;
void brute(const vector<ll> &v, const vector<char>& s, int idx)
{
	if (v.size() == 1)
	{
		mn = min(mn, v[0]);
		return;
	}
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = i + 1; j < v.size(); ++j)
		{
			vector<ll> v_copy = v;
			ll a = v[i], b = v[j];
			v_copy.erase(v_copy.begin() + j);
			v_copy.erase(v_copy.begin() + i);
			if (s[idx] == '+')
				v_copy.push_back(a + b);
			else
				v_copy.push_back(a * b);
			brute(v_copy, s, idx + 1);
		}
	}
}
int main()
{
	vector<ll> v(4);
	vector<char> s(3);
	for (int i = 0; i < 4; ++i)
		cin >> v[i];
	for (int i = 0; i < 3; ++i)
		cin >> s[i];
	brute(v, s, 0);
	cout << mn << endl;
}