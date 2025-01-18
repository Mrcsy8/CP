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
    ll n, k;
    cin >> n >> k;
    bool even_n = !(n % 4 == 1 || n % 4 == 2), even_k = !((n - k) % 4 == 1 || (n - k) % 4 == 2);
    if (even_n && even_k || !even_n && !even_k)
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