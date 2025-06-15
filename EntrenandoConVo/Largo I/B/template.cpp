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

int exc = 0, fal = 0;

void bal(int n, int m)
{
    if(n - m > 0)
    {
        exc += (n-m)/ 2;
    }
    else
    {
        fal += m-n;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, x, y, z;
    cin >> a >> b >> c;
    cin >> x >> y >> z;
    bal(a,x);
    bal(b,y);
    bal(c,z);
    if(exc >= fal)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    
    return 0;
}