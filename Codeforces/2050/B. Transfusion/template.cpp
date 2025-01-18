#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define F first
#define S second
#define PB push_back
#define MP make_pair

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    REP(i, 0, n)
    cin >> a[i];
    ll tot_a = 0, tot_b = 0;
    for (int i = 0; i < n; i += 2)
    {
        tot_a += a[i];
    }
    for (int i = 1; i < n; i += 2)
    {
        tot_b += a[i];
    }
    if ((tot_a * (n / 2) == tot_b * ceil(n / 2.0)) && tot_b % (n / 2) == 0 && tot_a % (ll)ceil(n / 2.0) == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
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