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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    REP(i, 0, n)
    cin >> a[i];
    REP(i, 0, n)
    cin >> b[i];
    int res = 0;
    REP(i, 0, n)
    {
        if (i + 1 != n && a[i] > b[i + 1])
            res += a[i] - b[i + 1];
        else if (i + 1 == n)
            res += a[i];
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