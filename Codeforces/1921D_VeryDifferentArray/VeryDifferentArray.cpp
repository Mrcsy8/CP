#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n), b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        ll d = 0;
        for (int i = 0; i < n; i++)
        {
            d += abs(a[i] - b[i]);
        }
        ll tot = d;
        for (int i = 0; i < n; i++)
        {
            tot = tot - abs(a[n - i - 1] - b[n - i - 1]) + abs(a[n - i - 1] - b[m - i - 1]);
            d = max(d, tot);
        }
        cout << d << "\n";
    }
    return 0;
}