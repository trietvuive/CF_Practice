#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int n, m;
const int MAX = 3e5 + 5;
int a[MAX], b[MAX];
bool check(int curr, int last = -1)
{
	for (int i = 0; i < m; ++i)
	{
		if (a[i] == curr || a[i] == last || b[i] == curr || b[i] == last) continue;
		else if (last != -1) return false;
		return check(curr, a[i]) || check(curr, b[i]);
	}
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
		scanf("%d %d", a+i, b+i);
	if (check(a[0]) || check(b[0]))
		printf("YES\n");
	else
		printf("NO\n");

}