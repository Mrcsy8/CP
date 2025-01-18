#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

void solve()
{
    ll x, y, k;
    cin >> x >> y >> k;
    x += k;
    ll cont = 0;
    while (x >= y)
    {
        if (x % y != 0)
            cont += x % y;
        if (cont > k)
            break;
        x = floor(x / y) + x % y;
    }
    cout << x << "\n";
    cout << cont << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}