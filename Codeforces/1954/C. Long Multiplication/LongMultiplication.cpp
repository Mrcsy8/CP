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
    string x, y;
    cin >> x >> y;
    bool bigger = false, set = false;
    vector<vector<char>> res(2, vector<char>(x.size()));
    for (int i = 0; i < x.size(); i++)
    {
        if (set == false)
        {
            if (x[i] > y[i])
                set = true;
            else if (y[i] > x[i])
            {
                set = true;
                bigger = true;
            }
            res[bigger][i] = max(x[i], y[i]);
            res[!bigger][i] = min(x[i], y[i]);
            continue;
        }
        res[!bigger][i] = max(x[i], y[i]);
        res[bigger][i] = min(x[i], y[i]);
    }
    for (auto &i : res)
    {
        for (auto &j : i)
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