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
        ll n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;
        ll l, r;
        if (x1 + y1 > n + 1)
        {
            l = n - max(x1, y1) + 1;
        }
        else
        {
            l = min(x1, y1);
        }
        if (x2 + y2 > n + 1)
        {
            r = n - max(x2, y2) + 1;
        }
        else
        {
            r = min(x2, y2);
        }

        cout << abs(r - l) << "\n";
    }
    return 0;
}