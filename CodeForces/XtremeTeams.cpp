#include <iostream>
using namespace std;
int main()
{
    int n, k, m, v, sum = 0; 
    cin >> n >> k; 
    for (int i = 0; i < k; i++) 
    {   
        cin >> m; 
        for (int j = 1; j <= m; j++) 
        { 
            cin >> v; 
            if (v == j)sum++; 
        } 
    }
    cout << (n - sum) * 2 - k + 1; return 0;
}