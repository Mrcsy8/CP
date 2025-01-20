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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        forn(i, n)
        {
            cin >> a[i];
        }
        forn(i, n)
        {
            cin >> b[i];
        }
        ll r = 0;
        bool res = true;
        forn(i, n)
        {
            if (a[i] - b[i] < 0 && r != 0)
            {
                res = false;
                break;
            }
            if (a[i] - b[i] < 0)
            {
                r = b[i] - a[i];
            }
        }
        if (res)
        {
            forn(i, n)
            {
                if (a[i] - b[i] >= 0 && a[i] - b[i] < r)
                {
                    res = false;
                    break;
                }
            }
        }
        if (res)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << "\n";
    }

    return 0;
}