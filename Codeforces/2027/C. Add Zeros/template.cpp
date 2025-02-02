#include <bits/stdc++.h>
using namespace std;

#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
#define forn(i, n) forsn(i, 0, n)
#define dforn(i, n) dforsn(i, 0, n)

#define pb push_back
#define pf push_front
#define mp make_pair
#define fst first
#define snd second

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) int((x).size())

typedef long long ll;

int n;
int saize;

ll dfs(vector<ll> &a, ll zero, map<ll, ll> &dp, map<ll, vector<ll>> &jumps)
{
    ll maxi = 0;
    if (jumps[zero].empty())
    {
        return 0;
    }
    for (auto i : jumps[zero])
    {
        if (dp.find({zero + i}) != dp.end())
            maxi = max(i + dp[zero + i], maxi);
        else
            maxi = max(i + dfs(a, zero + i, dp, jumps), maxi);
    }
    dp[zero] = maxi;
    return maxi;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> a(n);
        map<ll, ll> dp;
        map<ll, vector<ll>> jumps;
        saize = a.size();
        forn(i, n)
        {
            cin >> a[i];
        }
        forsn(i, 1, n)
        {
            ll req = a[i] - saize + i;
            if (req >= 0)
                jumps[req].pb(i);
        }
        cout << saize + dfs(a, 0, dp, jumps) << "\n";
    }
    return 0;
}