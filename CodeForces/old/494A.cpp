#include<bits/stdc++.h>
using namespace std;

char s[100002];

int main() {
	scanf("%s", s);
	int open = 0, close = 0, hash = 0, last_run = 0;
	for (int i = 0; s[i] != 0; ++i)
	{
		close += s[i] == ')', open += s[i] == '(', hash += s[i] == '#';
		if (s[i] == '#')last_run = 0;
		else last_run = max(0, last_run + (s[i] == '(' ? 1 : -1));

		if (hash + close > open || (s[i+1] == 0 && last_run > 0)) {
			cout << -1 << "\n";
			return 0;
		}
	}
	for (int i = 0; i < hash - 1; ++i)
		printf("%d\n", 1);
	printf("%d\n", open - close - hash + 1);
}