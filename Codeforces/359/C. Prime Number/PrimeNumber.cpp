#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

#define MOD (ll)(1e9 + 7)

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll power(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        ll p = power(a, b / 2);
        return p * p % MOD;
    }
    else
    {
        ll p = power(a, (b - 1) / 2);
        return p * p % MOD * a % MOD;
    }
}

void solve()
{
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    ll a_tot = 0;
    REP(i, 0, n)
    {
        cin >> a[i];
        a_tot = a_tot + a[i];
    }
    map<ll, int> cnt;
    REP(i, 0, n)
    {
        cnt[a_tot - a[i]]++;
    }
    int exp;
    ll cur = a_tot - a[n - 1];
    while (cur != a_tot && cnt[cur] % x == 0)
    {
        cnt[cur + 1] += cnt[cur] / x;
        cur++;
    }
    cout << power(x, cur);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}