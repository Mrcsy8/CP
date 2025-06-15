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
#define PNT(x) cout<<x<<"\n";

typedef long long ll;

const ll MOD = 1e9 + 7;

ll power(ll a, ll b, ll Mod)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        ll p = power(a, b / 2, Mod);
        return p * p % Mod;
    }
    else
    {
        ll p = power(a, (b - 1) / 2, Mod);
        return p * p % Mod * a % Mod;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        PNT(power(a,power(b,c,MOD-1), (MOD)));
    }
    return 0;
}