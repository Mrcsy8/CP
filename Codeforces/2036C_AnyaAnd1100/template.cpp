#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define F first
#define S second
#define PB push_back
#define MP make_pair

string s;

bool check(ll start)
{
    string sub_s = "1100";
    for (int i = 0; i < 4; ++i)
    {
        if (s[start + i] != sub_s[i])
            return false;
    }
    return true;
}

void solve()
{
    ll q;
    cin >> s >> q;
    ll s_len = s.length();
    queue<pair<ll, ll>> query;
    REP(i, 0, q)
    {
        ll j, k;
        cin >> j >> k;
        query.push(make_pair(j - 1, k));
    }
    ll count = 0;
    for (int i = 0; i < s_len - 3; ++i)
    {
        if (check(i) == true)
            count++;
    }
    while (!query.empty())
    {
        pair<ll, ll> ins = query.front();
        query.pop();
        for (int i = max(ins.F - 3, (ll)0); i < min(ins.F + 1, s_len - 3); ++i)
            count -= check(i);
        s[ins.F] = '0' + ins.S;
        for (int i = max(ins.F - 3, (ll)0); i < min(ins.F + 1, s_len - 3); ++i)
            count += check(i);
        if (count)
            cout << "YES\n";
        else
            cout << "NO\n";
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