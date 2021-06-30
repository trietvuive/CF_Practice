/*#include<iostream>
#include<string>
using namespace std;

int main()
{
	int cases;
	cin >> cases;
	string trash;
	getline(cin, trash);
	while (cases--)
	{
		string a, b;
		getline(cin, a);
		getline(cin, b);

        int max = 0;    // length of lcs

        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
				int ai = i, bi = j;
				while (ai<a.size() && bi < b.size() && a[ai] == b[bi])ai++, bi++;
				if (ai - i > max)
					max = ai - i;
            }
        }
        cout << a.size() + b.size() - max * 2 << endl;
	}
}
*/