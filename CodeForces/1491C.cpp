#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 5002
int T, N, a[MAXN], b[MAXN];
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N; For(i, 1, N)cin >> a[i], b[i] = 0;
        ll ans = 0; 
        For(i, 1, N) { 
            int tmp = b[i]; 
            //if we're traversing that square through other square more time than the square itself
            //there's no need to start on that square
            //if not, then we must start at that square a[1] - 1 - tmp times
            //so the total time we will touch that square is at least a[1] - 1
            if (tmp < a[i] - 1)
                ans += a[i] - 1 - tmp, tmp = a[i] - 1;

            //cross that square until it reaches 1, then cross 1 to reach the next square
            b[i + 1] += tmp - a[i] + 1; 
            //jump on that square until it goes to 1
            //on the way to 1, we also will step on square i+2 -> i + a[i]
            For(j, i + 2, min(N, i + a[i]))
                b[j]++; 
        }
        cout << ans << endl;
    }
    return 0;
}
