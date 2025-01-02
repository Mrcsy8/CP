#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

int n;

int en_vecinos(vector<int> &a, int pos)
{
    int res = 0;
    if (pos == n - pos - 1 && pos != 0)
    {
        if (a[pos - 1] == a[pos])
            res++;
        if (a[pos + 1] == a[pos])
            res++;
    }
    else if (pos == n - pos - 2)
    {
        res++;
        if (a[pos - 1] == a[pos])
            res++;
        if (a[pos + 2] == a[pos])
            res++;
    }
    else
    {
        if (pos != 0)
        {
            if (a[pos - 1] == a[pos])
                res++;
            if (a[n - pos - 1] == a[n - pos])
                res++;
        }
        if (a[pos + 1] != a[n - pos - 2])
        {
            if (a[pos + 1] == a[pos])
                res++;
            if (a[n - pos - 1] == a[n - pos - 2])
                res++;
        }
    }

    return res;
}
void solve()
{
    cin >> n;
    vector<int> a(n);
    REP(i, 0, n)
    cin >> a[i];
    int res = 0;
    int lim = n / 2 + n % 2;
    REP(i, 0, lim)
    {
        if (a[i] == a[n - i - 1])
            res += en_vecinos(a, i);
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