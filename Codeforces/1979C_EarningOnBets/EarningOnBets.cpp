#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

ll maximoComunDivisor(ll a, ll b)
{
    if (min(a, b) == 0)
        return max(a, b);
    return maximoComunDivisor(max(a, b) % min(a, b), min(a, b));
}

ll minimoComunMultiplo(ll a, ll b)
{
    return a / maximoComunDivisor(a, b) * b;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> k(n);

    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }
    ll mcm = 1;
    for (int i = 0; i < n; i++)
        mcm = minimoComunMultiplo(mcm, k[i]);
    double long check_sum = 0;
    for (int i = 0; i < n; i++)
    {
        check_sum += mcm / k[i];
    }
    if (check_sum < mcm)
    {
        for (int i = 0; i < n; i++)
            cout << mcm / k[i] << " ";
        cout << "\n";
    }
    else
        cout << "-1\n";
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