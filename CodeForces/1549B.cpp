#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	int i = 1;
	while (tc-- > 0)
	{
		int n;  cin >> n;
		string my_pawn, your_pawn;
		cin >> your_pawn;
		cin >> my_pawn;
		int ans = 0;
		for (int i = 0; i < my_pawn.size(); ++i)
		{
			if (my_pawn[i] == '1')
			{
				if (i > 0 && your_pawn[i - 1] == '1')++ans, your_pawn[i - 1] = '#';
				else if (your_pawn[i] == '0')++ans, your_pawn[i] = '#';
				else if (i + 1 < your_pawn.size() && your_pawn[i + 1] == '1') ++ans, your_pawn[i+1] = '#';

			}
		}
		printf("%d\n", ans);
	}
}