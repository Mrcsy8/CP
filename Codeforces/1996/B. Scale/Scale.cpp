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
    int n, k;
    cin >> n >> k;
    int ratio = n / k;
    vector<vector<char>> res(ratio);
    REP(i, 0, n)
    {
        string line;
        cin >> line;
        REP(j, 0, line.size())
        {
            if (i % k == 0 && j % k == 0)
                res[i / k].push_back({line[j]});
        }
    }
    for (const auto &i : res)
    {
        for (const auto &j : i)
        {
            cout << j;
        }
        cout << "\n";
    }
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