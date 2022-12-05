#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		int n; cin >> n;
		unordered_set<int> s;
		for (int i = 0; i < n; ++i)
		{
			int element; cin >> element;
			while (element > 1 and (s.find(element) != s.end() or element > n))
				element /= 2;
			s.insert(element);
		}
		cout << (s.size() == n ? "YES" : "NO") << endl;
	}
}