#include<bits/stdc++.h>
using namespace std;
#define sqr(X) (X)*(X)
int p[] = { 0,1,2,3,4,5,6,7,8 };
int x[9], y[9];
int d(int a, int b) {
    return sqr(x[p[a]] - x[p[b]]) + sqr(y[p[a]] - y[p[b]]); 
}
int main()
{
    for (int i = 1; i <= 8; i++)scanf("%d%d", &x[i], &y[i]);
    do if (d(1, 2) == d(2, 3) && d(2, 3) == d(3, 4) && d(3, 4) == d(4, 1) && d(1, 3) == d(2, 4) && 
        d(5, 6) == d(7, 8) && d(6, 7) == d(5, 8) && d(5, 7) == d(6, 8))
        return cout << "YES" << "\n" << p[1] << " " << p[2] << " " << p[3] << " " << p[4]
        << "\n" << p[5] << " " << p[6] << " " << p[7] << " " << p[8] << "\n", 0;
    while (next_permutation(p + 1, p + 9));
    cout << "NO" << "\n";
    return 0;
}