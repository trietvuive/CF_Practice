/*#include<iostream>
#include<string>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	for (int i = 1; i <= cases; i++)
	{
		int cost = 0;
		int cj, jc;
		string s;
		cin >> cj >> jc >> s;
		char previous = '#';
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != '?')
			{
				if (previous == '#')
					previous = s[i];
				else
				{
					if (previous == 'C' && s[i] == 'J')
						cost += cj;
					else if (previous == 'J' && s[i] == 'C')
						cost += jc;
					previous = s[i];
				}
			}
		}
		cout << "Case #" << i << ": " << cost << endl;
	}
}
*/