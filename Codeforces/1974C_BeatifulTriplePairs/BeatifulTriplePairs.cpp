#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)
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
    ll res = 0;

    map<pair<ll, ll>, pair<unordered_multiset<ll>, unordered_set<ll>>> duplas;

    for (int i = 0; i < n - 2; i++)
    {
        duplas[MP(a[i], a[i + 1])].F.insert(a[i + 2]);
        duplas[MP(a[i], a[i + 1])].S.insert(a[i + 2]);
    }
    for (auto &i : duplas)
    {
        if (i.S.S.size() > 1)
            res += i.S.F.size() - 1;
    }

    duplas.clear();
    for (int i = 1; i < n - 1; i++)
    {
        duplas[MP(a[i], a[i + 1])].F.insert(a[i - 1]);
        duplas[MP(a[i], a[i + 1])].S.insert(a[i - 1]);
    }
    for (auto &i : duplas)
    {
        if (i.S.S.size() > 1)
            res += i.S.F.size() - 1;
    }
    duplas.clear();
    for (int i = 0; i < n - 2; i++)
    {
        duplas[MP(a[i], a[i + 2])].F.insert(a[i + 1]);
        duplas[MP(a[i], a[i + 2])].S.insert(a[i + 1]);
    }
    for (auto &i : duplas)
    {
        if (i.S.S.size() > 1)
            res += i.S.F.size() - 1;
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