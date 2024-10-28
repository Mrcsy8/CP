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
    unordered_map<int, int> divs;
    REP(i, 0, n)
    {
        int maxi = 1;
        for (int j = 1; j * j <= a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                int other_div = a[i] / j;
                if (j != 1 && j != other_div)
                    divs[j]++;
                divs[other_div]++;
                maxi = max(maxi, max(divs[j], divs[other_div]));
            }
        }
        for (int j = 1; j * j <= a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                int other_div = a[i] / j;
                if (j != 1 && j != other_div)
                    divs[j] = maxi;
                divs[other_div] = maxi;
            }
        }
    }
    int res = 1;
    for (auto &i : divs)
        res = max(res, i.S);
    cout << res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}