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

vector<ll> factors(ll n)
{
    vector<ll> f;
    for(ll x = 2; x*x <= n; x++)
    {
        while(n%x == 0)
        {
            f.pb(x);
            n /= x;
        }
    }
    if(n > 1)
    {
        f.pb(n);
    }
    return f;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    forn(i,n)
    {
        cin >> a[i];
    }
    return 0;
}