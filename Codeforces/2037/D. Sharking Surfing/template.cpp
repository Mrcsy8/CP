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
    int n, m;
    ll L;
    cin >> n >> m >> L;
    vector<ll> l(n), r(n), x(m), v(m);
    REP(i, 0, n)
    cin >> l[i] >> r[i];
    REP(i, 0, m)
    cin >> x[i] >> v[i];
    ll res = 0, jump = 1;
    bool ans = true;
    ll j = 0;
    priority_queue<ll> jumps;
    for (ll i = 0; i < n; ++i)
    {
        if (jump < r[i] - l[i] + 2)
        {
            while (x[j] < l[i] && j < m)
            {
                jumps.push({v[j]});
                j++;
            }
            while (!jumps.empty() && jump < r[i] - l[i] + 2)
            {
                jump += jumps.top();
                jumps.pop();
                res++;
            }
            if (jump < r[i] - l[i] + 2)
            {
                ans = false;
                break;
            }
        }
    }
    if (ans)
    {
        cout << res << "\n";
    }
    else
        cout << -1 << "\n";
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