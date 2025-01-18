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
    bool mountain = false;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            mountain = false;
        }
        else
        {
            if (!mountain)
            {
                mountain = true;
                res++;
            }
        }
    }
    if (res > 1)
        cout << 2 << "\n";
    else
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