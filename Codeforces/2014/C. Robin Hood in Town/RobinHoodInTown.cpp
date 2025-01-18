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
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll tot = 0;
    REP(i, 0, n)
    {
        cin >> a[i];
        tot += a[i];
    }
    sort(a.begin(), a.end());
    if (n == 1 || n == 2)
        cout << "-1\n";
    else
    {
        ll low_aver = a[floor(n / 2.0)] * n;
        ll x;
        if (low_aver >= tot / 2.0)
            x = ceil((low_aver - (tot / 2.0)) * 2) + 1;
        else
            x = 0;

        cout << x << "\n";
    }
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