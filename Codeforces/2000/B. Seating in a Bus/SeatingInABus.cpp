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
    int n;
    cin >> n;
    vector<bool> a_i(n, false);
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        a--;
        a_i[a] = true;
        if (i != 0)
            if ((a == 0 && !a_i[a + 1]) || (a == n - 1 && !a_i[a - 1]) || (!a_i[a - 1] && !a_i[a + 1]))
                ans = false;
    }
    (ans) ? cout << "YES\n" : cout << "NO\n";
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