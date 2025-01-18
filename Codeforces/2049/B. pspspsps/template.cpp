#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define F first
#define S second
#define PB push_back
#define MP make_pair

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ans = true;
    if (s[0] == 's')
        s[0] = '.';
    if (s[n - 1] == 'p')
        s[n - 1] = '.';
    char let = '.';
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'p')
        {
            if (let == 's')
            {
                ans = false;
                break;
            }
            let = 'p';
        }
        if (s[i] == 's')
        {
            if (let == 'p')
            {
                ans = false;
                break;
            }
            let = 's';
        }
    }
    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
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