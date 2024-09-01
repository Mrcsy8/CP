#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

int n, k;

ll solve_four(vector<int> &a)
{
    int res = 4;
    bool two = false;
    REP(i, 0, n)
    {
        switch (a[i] % 4)
        {
        case 0:
            return 0;
            break;
        case 1:
            res = min(res, 2);
            break;
        case 2:
            if (two)
                return 0;
            two = true;
            res = 1;
            break;
        case 3:
            res = 1;
            break;
        }
    }
    return res;
}
int solve_prime(vector<int> &a)
{
    int rest = 1;
    REP(i, 0, n)
    {
        if (a[i] % k == 0)
        {
            rest = 0;
            break;
        }
        if (a[i] % k > rest)
            rest = a[i] % k;
    }
    return rest;
}

void solve()
{
    cin >> n >> k;
    vector<int> a(n);
    REP(i, 0, n)
    {
        int input;
        cin >> input;
        a[i] = input % k;
    }
    int ans;
    if (n == 1)
        ans = (k - a[0] % k) % k;
    else if (k != 4)
        ans = (k - solve_prime(a)) % k;
    else
        ans = solve_four(a);
    cout << ans << "\n";
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