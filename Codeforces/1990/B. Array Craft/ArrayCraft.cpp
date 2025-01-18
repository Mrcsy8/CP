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
    int n, y, x;
    cin >> n >> x >> y;
    x--;
    y--;
    for (int i = 0; i <= y; i++)
        (y - i) % 2 ? cout << "-1 " : cout << "1 ";
    for (int i = y + 1; i <= x; i++)
        cout << "1 ";
    for (int i = x + 1; i < n; i++)
        (i - x) % 2 ? cout << "-1 " : cout << "1 ";
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