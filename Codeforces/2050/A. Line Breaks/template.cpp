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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    REP(i, 0, n)
    cin >> s[i];
    vector<int> s_size(n);
    REP(i, 0, n)
    s_size[i] = s[i].size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        m -= s_size[i];
        if (m < 0)
            break;
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