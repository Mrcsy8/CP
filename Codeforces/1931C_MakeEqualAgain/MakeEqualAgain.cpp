#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

int n;

int search(vector<int> &a, int &num)
{
    int l, r;
    bool check_equal = true;
    REP(i, 0, n)
    {
        if (num != a[i])
        {
            check_equal = false;
            l = i;
            break;
        }
    }
    if (check_equal)
        return 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (num != a[i])
        {
            r = i;
            break;
        }
    }
    return r - l + 1;
}

void solve()
{
    cin >> n;
    vector<int> a(n);
    REP(i, 0, n)
    cin >> a[i];
    int streak[2] = {0};

    streak[0] = search(a, a[0]);
    streak[1] = search(a, a[n - 1]);

    cout << min(streak[0], streak[1]) << "\n";
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