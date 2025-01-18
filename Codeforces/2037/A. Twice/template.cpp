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
    sort(a.begin(), a.end());
    int cont = 0, res = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == a[i - 1])
        {
            cont = max(1, cont);
            cont++;
        }

        else
        {
            res += cont / 2;
            cont = 0;
        }
    }
    res += cont / 2;
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