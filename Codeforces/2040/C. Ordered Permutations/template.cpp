#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define F first
#define S second
#define PB push_back
#define MP make_pair

ll power(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        ll p = power(a, b / 2);
        return p * p;
    }
    else
    {
        ll p = power(a, (b - 1) / 2);
        return p * p * a;
    }
}

void solve()
{
    int n;
    ll k;
    cin >> n >> k;
    k--;
    if (n == 1)
    {
        if (k == 0)
            cout << "1\n";
        else
            cout << "-1\n";
        return;
    }
    if (log2(k) >= n - 1)
    {
        cout << "-1\n";
        return;
    }
    vector<int> res(n, 0);
    ll r = 0, l = n - 1;
    ll i = n - 2, num = 1;
    while (i > 40)
    {
        res[l] = num;
        l--;
        i--;
        num++;
    }
    i = (ll)1 << (min(40, (n - 2)));
    while (i != 0)
    {
        if (!(k & i))
        {
            res[l] = num;
            l--;
        }
        else
        {
            res[r] = num;
            r++;
        }
        i = i >> 1;
        num++;
    }
    res[l] = n;
    for (int i = n - 1; i >= 0; i--)
        cout << res[i] << " ";
    cout << "\n";
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