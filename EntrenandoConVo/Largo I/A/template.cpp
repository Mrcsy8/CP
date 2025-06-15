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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> m(366, 0), f(366, 0);
    forn(i,n)
    {
        char input;
        int l, r;
        cin >> input >> l >> r;
        if(input == 'F')
        {
            forsn(j,l-1,r)
            {
                f[j]++;
            }
        }
        else
        {
            forsn(j,l-1,r)
            {
                m[j]++;
            }
        }
    }
    int res = 0;
    forn(i,366)
    {
        res = max(min(m[i],f[i])*2, res);
    }
    cout << res << "\n";
    return 0;
}