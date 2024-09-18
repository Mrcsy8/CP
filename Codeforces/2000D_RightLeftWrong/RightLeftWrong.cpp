#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

int n;

int previous(int &r, string &s)
{
    while (r > 0)
    {
        r--;
        if (s[r] == 'R')
            return r;
    }
    return 0;
}

int next(int &l, string &s)
{
    while (l < n)
    {
        l++;
        if (s[l] == 'L')
            return l;
    }
    return n;
}

void solve()
{
    cin >> n;
    vector<int> a(n);
    vector<ll> part_sum(n + 1);
    REP(i, 0, n)
    cin >> a[i];
    string s;
    cin >> s;
    part_sum[0] = 0;
    REP(i, 1, n + 1)
    part_sum[i] = part_sum[i - 1] + a[i - 1];

    ll res = 0;
    int l = -1, r = n;
    r = previous(r, s);
    l = next(l, s);
    while (l != n - 1 && r != 0 && l < r)
    {
        res += part_sum[r + 1] - part_sum[l];
        r = previous(r, s);
        l = next(l, s);
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