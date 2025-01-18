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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<bool> remain(k, false);
    set<int> remainders;
    REP(i, 0, n)
    cin >> a[i];
    REP(i, 0, n)
    {
        if (remainders.find(a[i] % k) == remainders.end())
            remainders.insert(a[i] % k);
        else
            remain[a[i] % k] = true;
    }
    bool ans = false;
    REP(i, 0, k)
    {
        if (remain[i] == false)
        {
            REP(j, 0, n)
            if (a[j] % k == i)
            {
                cout << "YES\n"
                     << j + 1 << "\n";
                return;
            }
        }
    }
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