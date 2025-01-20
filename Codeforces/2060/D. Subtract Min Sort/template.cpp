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
        vector<ll> a(n);
        forn(i, n)
        {
            cin >> a[i];
        }
        vector<ll> a_2(n);
        forn(i, n - 1)
        {
            ll temp = min(a[i], a[i + 1]);
            a[i] = a[i] - temp;
            a[i + 1] = a[i + 1] - temp;
        }
        bool res = true;
        forn(i, n - 1)
        {
            if (a[i + 1] < a[i])
            {
                res = false;
                break;
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