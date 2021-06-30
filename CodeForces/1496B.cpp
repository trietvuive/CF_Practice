/*#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

int main()
{
	int cases;
	cin >> cases;
	while (cases--)
	{
		int n, k, max = 0, mex = 0;
		unordered_set<int> s;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			int element;
			cin >> element;
			s.insert(element);
			if (element > max) max = element;
		}
		while (s.find(mex) != s.end())
			mex++;
		if (k == 0)
			cout << n << endl;
		else if (mex > max)
			cout << n + k << endl;
		else
		{
			s.insert((mex + max + 1) / 2);
			cout << s.size() << endl;
		}
	}
}
*/