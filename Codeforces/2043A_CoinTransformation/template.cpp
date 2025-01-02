#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define F first
#define S second
#define PB push_back
#define MP make_pair
vector<ll> powers_2;
void power_2(ll n)
{
    ll x = 1;
    powers_2.PB(x);
    while (x <= n)
    {
        x *= 2;
        powers_2.PB(x);
    }
}

ll binary_search(ll n, vector<ll> &m)
{
    ll l = 0, r = m.size() - 1, i = m.size() / 2;
    while (r - l > 1)
    {
        if (m[i] < n)
            l = i;
        else if (m[i] > n)
            r = i;
        else
            return m[i];
        i = (r + l) / 2;
    }
    return m[l];
}
void solve()
{
    ll n;
    cin >> n;
    n = sqrtl(n);
    cout << binary_search(n, powers_2) << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    power_2(10e9);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}