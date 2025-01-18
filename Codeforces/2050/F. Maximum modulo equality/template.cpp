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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), l(q), r(q);
    REP(i, 0, n)
    cin >> a[i];
    REP(i, 0, q)
    {
        cin >> l[i];
        cin >> r[i];
        l[i]--;
        r[i]--;
    }
    if (n == 1)
    {
        REP(i, 0, q)
        cout << 0 << " ";
        cout << "\n";
        return;
    }
    vector<ll> dif(n - 1);
    REP(i, 0, n - 1)
    dif[i] = abs(a[i] - a[i + 1]);
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