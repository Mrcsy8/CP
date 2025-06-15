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
#define DBG(x) cout<<#x<<" = "<<(x)<<endl;

typedef long long ll;

ll res = LONG_LONG_MAX;

ll search(vector<vector<ll>> &grid, int n, int m, int k)
{
    forn(i,m)
    {
        multiset<ll> ms;
        forn(j,k)
        {
            ms.insert(grid[i][j]);
        }
        forn(j,n)
        {
            ll p = grid[i][j];
            grid[i][j] = *ms.rbegin();
            ms.erase(ms.find(p));
            if(j+k<n)
            {
                ms.insert(grid[i][j+k]);
            }
            else
            {
                ms.insert(LLONG_MAX);
            }
        }
    }
    forn(i,n)
    {
        multiset<ll> ms;
        forn(j,k)
        {
            ms.insert(grid[j][i]);
        }
        forn(j,m)
        {
            ll p = grid[j][i];
            grid[j][i] = *ms.rbegin();
            ms.erase(ms.find(p));
            if(j+k<m)
            {
                ms.insert(grid[j+k][i]);
            }
            else
            {
                ms.insert(LLONG_MAX);
            }
        }
    }
    ll res = LLONG_MAX;
    forn(i,n)
    {
        forn(j,m)
        {
            res = min(res,grid[j][i]);
        }
    }
    if(res == LLONG_MAX)
    {
        return -1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<vector<ll>> grid(m, vector<ll>(n, LLONG_MAX));
    forn(i,q)
    {
        int x, y;
        ll t;
        cin >> x >> y >> t;
        grid[y-1][x-1] = t;
    }
    cout << search(grid, n, m, k) << "\n";
    return 0;
}