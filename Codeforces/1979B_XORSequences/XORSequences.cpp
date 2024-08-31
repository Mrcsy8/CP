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
    ll x, y;
    cin >> x >> y;
    ll cont = 1, ans = 1;
    REP(i, 0, ceil(max(log2(x), log2(y))))
    {
        if ((x & (1 << i)) && (y & (1 << i)) || !(x & (1 << i)) && !(y & (1 << i)))
            cont *= 2;
        else
            break;
    }
    ans = max(ans, cont);
    cout << ans << "\n";
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