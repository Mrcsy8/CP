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
    int robin = 0;
    int give = 0;
    REP(i, 0, n)
    {
        int a;
        cin >> a;
        if (a >= k)
            robin += a;
        else if (a == 0 && robin > 0)
        {
            robin--;
            give++;
        }
    }
    cout << give << "\n";
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