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
    vector<ll> part_sum(n + 1);
    part_sum[0] = 0;
    for (int i = 1; i <= n; i++)
        part_sum[i] = a[i - 1] + part_sum[i - 1];
    set<ll> box;
    ll res = 0;
    for (int i = 0; i <= n; i++)
    {
        if ((i != 0 && a[i - 1] == 0) || box.find(part_sum[i]) != box.end())
        {
            box.clear();
            box.insert(part_sum[i]);
            res++;
        }
        else
            box.insert(part_sum[i]);
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