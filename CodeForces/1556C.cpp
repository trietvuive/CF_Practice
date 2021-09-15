#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1001];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = 0;
    for (int i = 1; i <= n; i += 2) {
        long long balance = 0, free = a[i];//free = how many open bracket can cross. if the sequence is ((( ))..., only one bracket is free to cross over.
        for (int j = i + 1; j <= n; j += 2) {
            ans += max(0ll, free - max(0ll, balance + a[j - 1] - a[j]) + 1);//calculate the number of closing bracket available to pair with free open bracket at the beginning
            //+1 since you can form a crossover bracket with 0 free bracket. sth like 1 1 2 3 => ..() (()).. 
            if (j == i + 1)--ans;
            //-- since +1 doesn't apply for adjacent bracket, only crossover bracket.
            balance += a[j - 1] - a[j];
            free = min(free, balance);
        }
    }
    cout << ans << endl;
}
