/*#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string s;
		cin >> n >> s;
		int first_open = 0, second_open = 0, zero_count = 0;
		string first(n,'*'), second(n,'*');
		bool alternate = true;
		for (int i = 0; i < s.size(); ++i)
			if (s[i] == '0' && alternate)
				first[i] = '(', second[i] = ')', alternate = !alternate, ++zero_count;
			else if (s[i] == '0' && !alternate)
				first[i] = ')', second[i] = '(', alternate = !alternate, ++zero_count;
		int one_count = n - zero_count, temp = 0;
		for (int i = 0; i < n; ++i)
		{
			if (first[i] == '*')
			{
				if (temp < one_count / 2)
					first[i] = '(', second[i] = '(';
				else
					first[i] = ')', second[i] = ')';
				++temp;
			}
		}
		bool wrong = false;
		for (int i = 0; i < n; ++i)
		{
			if (first[i] == '(')++first_open;
			else --first_open;
			if (second[i] == '(')++second_open;
			else --second_open;
			if (first_open < 0 || second_open < 0)
			{
				wrong = true;
				break;
			}
		}
		if (wrong || one_count % 2 == 1)
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			cout << first << endl;
			cout << second << endl;
		}
	}
}
*/