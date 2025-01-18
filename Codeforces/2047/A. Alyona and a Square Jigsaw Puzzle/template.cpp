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
    vector<int> a(n);
    REP(i, 0, n)
    cin >> a[i];
    ll sum = 0, res = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += a[i];
        if (pow(floor(sqrt(sum)), 2) == sum && (int)floor(sqrt(sum)) % 2 == 1)
            res++;
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