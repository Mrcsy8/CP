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
    vector<int> a(n);
    REP(i, 0, n)
    cin >> a[i];
    bool ans = true;
    REP(i, 0, n - 1)
    {
        if (abs(a[i] - a[i + 1]) != 5 && abs(a[i] - a[i + 1]) != 7)
        {
            ans = false;
            break;
        }
    }
    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
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