#include<iostream>
#include<string>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	while (cases--)
	{
		int n, k;
		string s;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			char c;
			cin >> c;
			s += c;
		}
		int left = 0, right = n - 1;
		while (s[left] == s[right] && left < right)
			left++, right--;
		if (left+1 > k && n>k*2)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
