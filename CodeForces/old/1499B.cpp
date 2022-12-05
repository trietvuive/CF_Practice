#include<string>
#include<iostream>
using namespace std;
bool removable(const string& s)
{
	bool one = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '1' && i+1<s.size() && s[i + 1] == '0')
			i++;
		else if (s[i] == '1')
			one = true;
		else if (one)
			return false;
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	while (n--)
	{
		getline(cin, line);
		if (removable(line))
		{
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}
}
