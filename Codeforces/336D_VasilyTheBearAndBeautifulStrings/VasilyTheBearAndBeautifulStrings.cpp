#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

const ll MOD = 1e9 + 7;
vector<ll> factorial;
vector<ll> inverse_factorial;

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

void fact_to_n(ll n)
{
    factorial[0] = 1;
    for (int i = 1; i <= n; i++)
        factorial[i] = factorial[i - 1] * i % MOD;
}

void inv_fact_to_n(ll n)
{
    inverse_factorial[n] = power(factorial[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--)
        inverse_factorial[i] = inverse_factorial[i + 1] * (i + 1) % MOD;
}

ll comb_num(ll n, ll m)
{
    return (factorial[n] * inverse_factorial[n - m] % MOD) * inverse_factorial[m] % MOD;
}

ll resolver(int n, int m, bool g)
{
    if (n == 0)
    {
        if (m == 1)
            return g;
        if (!g)
            return 1;
        return 0;
    }
    if (m == 0)
    {
        if (n % 2 == !g)
            return 1;
        return 0;
    }
    if (!g)
        return (comb_num(n + m - 1, n) + resolver(n - 1, m, 1)) % MOD;
    return resolver(n - 1, m, 0);
}

void solve()
{
    int n, m;
    bool g;
    cin >> n >> m >> g;
    factorial.resize(n + m);
    fact_to_n(n + m - 1);
    inverse_factorial.resize(n + m);
    inv_fact_to_n(n + m - 1);
    cout << resolver(n, m, g);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}