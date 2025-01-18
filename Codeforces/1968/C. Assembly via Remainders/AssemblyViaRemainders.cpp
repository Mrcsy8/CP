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
    vector<int> x(n - 1);
    vector<ll> a(n);
    REP(i, 0, n - 1)
    cin >> x[i];
    a[0] = x[0] + 1;
    REP(i, 1, n)
    {
        ll add;
        if (i < n - 1)
            add = x[i] + x[i - 1] - x[i] % a[i - 1];
        else
            add = x[i - 1];
        a[i] = a[i - 1] + add;
    }
    for (auto &i : a)
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