#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define F first
#define S second
#define PB push_back
#define MP make_pair

ll find_min(vector<ll> &a, ll b, ll f)
{
    ll best = 0, sum = 0;
    for (ll i = b; i < f; ++i)
    {
        sum = min(a[i], sum + a[i]);
        best = min(sum, best);
    }
    return best;
}

ll find_max(vector<ll> &a, ll b, ll f)
{
    ll best = 0, sum = 0;
    for (ll i = b; i < f; ++i)
    {
        sum = max(a[i], sum + a[i]);
        best = max(sum, best);
    }
    return best;
}

void find_min_max_lr(vector<ll> &a, ll b, ll f, ll &mini, ll &maxi)
{
    mini = a[b], maxi = a[b];
    ll sum = 0;
    for (ll i = b; i < f; ++i)
    {
        sum += a[i];
        mini = min(mini, sum);
        maxi = max(maxi, sum);
    }
}

void find_min_max_rl(vector<ll> &a, ll b, ll f, ll &mini, ll &maxi)
{
    mini = a[b], maxi = a[b];
    ll sum = 0;
    for (ll i = b; i > f; --i)
    {
        sum += a[i];
        mini = min(mini, sum);
        maxi = max(maxi, sum);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    set<ll> sums = {0};
    ll x;
    bool x_found = false;
    REP(i, 0, n)
    {
        cin >> a[i];
        if (a[i] != -1 && a[i] != 1)
        {
            x = i;
            x_found = true;
        }
    }
    if (x_found)
    {
        ll min_l = find_min(a, 0, x);
        ll max_l = find_max(a, 0, x);
        for (ll i = min_l; i <= max_l; ++i)
            sums.insert(i);
        ll min_r = find_min(a, x + 1, a.size());
        ll max_r = find_max(a, x + 1, a.size());
        for (ll i = min_r; i <= max_r; ++i)
            sums.insert(i);

        ll min_l_rl, max_l_rl;
        find_min_max_rl(a, x, -1, min_l_rl, max_l_rl);
        ll min_r_lr, max_r_lr;
        find_min_max_lr(a, x, a.size(), min_r_lr, max_r_lr);
        for (ll i = min(min_l_rl, min(min_r_lr, min_l_rl + min_r_lr - a[x])); i <= max(max_l_rl, max(max_r_lr, max_l_rl + max_r_lr - a[x])); ++i)
            sums.insert(i);
    }
    else
    {
        ll mini = find_min(a, 0, a.size());
        ll maxi = find_max(a, 0, a.size());
        for (ll i = mini; i <= maxi; i++)
            sums.insert(i);
    }
    cout << sums.size() << "\n";
    for (auto &i : sums)
        cout << i << " ";
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