/*#include<iostream>
using namespace std;
const int MAX = 10e5 + 2;
int ar[MAX];
int main()
{
	int n, q, one_count = 0, zero_count = 0;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		if (ar[i] == 1)one_count++;
		else zero_count++;
	}
	for (int i = 0; i < q; i++)
	{
		int type, para;
		cin >> type >> para;
		if (type == 2)
			cout << (para <= one_count ? 1 : 0) << endl;
		else
		{
			if (ar[para])one_count--, zero_count++;
			else one_count++, zero_count--;
			ar[para] = !ar[para];
		}
	}
}
*/