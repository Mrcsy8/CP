#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = n; i >= k; i--)
    {
        cout << i << " ";
    }
    for (int i = m + 1; i < k; i++)
    {
        cout << i << " ";
    }
    for (int i = 1; i <= m; i++)
    {
        cout << i << " ";
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