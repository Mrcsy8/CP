#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

ll sumaGauss(ll a)
{
    return (a * (a + 1)) / 2;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll res = 0;

    for (int i = 0; i < 2; i++)
    {
        ll maxi = 0;
        set<ll> s;
        for (int i = 0; i < n; i++)
        {
            res += a[i];
            if (s.find(a[i]) != s.end())
                maxi = max(a[i], maxi);
            else
                s.insert(a[i]);
            a[i] = maxi;
        }
    }
    for (int i = 0; i < n; i++)
    {
        res += a[i] * (n - i);
    }
    cout << res << "\n";
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