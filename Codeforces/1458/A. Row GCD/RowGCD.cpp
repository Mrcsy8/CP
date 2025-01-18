#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)
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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    REP(i, 0, n)
    cin >> a[i];
    REP(i, 0, m)
    cin >> b[i];
    ll GCD;
    if (n == 1)
        GCD = 0;
    else
        GCD = a[1] - a[0];
    REP(i, 2, n)
    GCD = gcd(a[i] - a[0], GCD);
    REP(i, 0, m)
    cout << abs(gcd(a[0] + b[i], GCD)) << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}