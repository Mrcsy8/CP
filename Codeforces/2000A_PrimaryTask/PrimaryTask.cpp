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
    int a;
    cin >> a;
    int a2 = a;
    int i = 2;
    int digits = 0;
    while (a2 != 0)
    {
        a2 = a2 / 10;
        digits++;
    }
    (floor(a / pow(10, digits - 2)) == 10 && a - pow(10, digits - 1) >= pow(10, digits - 3) && a - 100 > 1) ? cout << "YES\n" : cout << "NO\n";
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