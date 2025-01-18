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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m), q(k);
    REP(i, 0, m)
    cin >> a[i];
    REP(i, 0, k)
    cin >> q[i];
    bool res = true;
    set<int> ans;
    for (int i = 1; i <= n; i++)
        ans.insert(i);
    for (int i = 0; i < k; i++)
        ans.erase(q[i]);
    for (int i = 0; i < m; i++)
    {
        if (ans.size() == 0 || (ans.find(a[i]) != ans.end() && ans.size() == 1))
            cout << "1";
        else
            cout << "0";
    }
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