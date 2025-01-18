#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define F first
#define S second
#define PB push_back
#define MP make_pair

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve()
{
    ll l, r, G;
    cin >> l >> r >> G;
    l = (l + (G - (l % G)) % G) / G;
    r = (r - (r % G)) / G;
    ll A, B;
    bool found = false;
    for (ll i = 0; i <= r - l; ++i)
    {
        for (ll j = 0; j <= i; ++j)
        {
            if (gcd(l + j, r - i + j) == 1)
            {
                A = l + j;
                B = r - i + j;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }
    if (found)
        cout << A * G << " " << B * G << "\n";
    else
        cout << "-1 -1\n";
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