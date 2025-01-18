#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

int n;

int min_diagonal(vector<vector<int>> &a, int offset)
{
    int mini;
    if (offset < 0)
    {
        offset = abs(offset);
        mini = a[0][offset];
        int i = 1, j = offset + 1;
        while (i < n && j < n)
        {
            mini = min(mini, a[i][j]);
            i++;
            j++;
        }
    }
    else
    {
        mini = a[offset][0];
        int i = offset + 1, j = 1;
        while (i < n && j < n)
        {
            mini = min(mini, a[i][j]);
            i++;
            j++;
        }
    }
    return mini;
}

void solve()
{

    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    REP(i, 0, n)
    REP(j, 0, n)
    cin >> a[i][j];
    int res = 0;
    for (int i = -n + 1; i < n; i++)
    {
        int mini = min_diagonal(a, i);
        if (mini < 0)
            res -= mini;
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