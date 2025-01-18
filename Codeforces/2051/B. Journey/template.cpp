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
    ll n;
    int a, b, c;
    cin >> n >> a >> b >> c;
    ll m = a + b + c;
    ll res = (n / m) * 3;
    n = n % m;
    if (n == 0)
    {
        cout << res << "\n";
        return;
    }
    res++;
    n = n - a;
    if (n <= 0)
    {
        cout << res << "\n";
        return;
    }
    res++;
    n = n - b;
    if (n <= 0)
    {
        cout << res << "\n";
        return;
    }
    res++;
    n = n - c;
    if (n <= 0)
    {
        cout << res << "\n";
        return;
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