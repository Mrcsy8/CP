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
    ll n, k;
    cin >> n >> k;
    map<ll, ll> bottles;
    REP(i, 0, k)
    {
        ll b, c;
        cin >> b >> c;
        bottles[b] += c;
    }
    vector<ll> values;
    for (auto &i : bottles)
        values.push_back(i.S);
    sort(values.begin(), values.end(), greater<ll>());
    ll res = 0;
    for (int i = 0; i < n && i < values.size(); ++i)
        res += values[i];
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