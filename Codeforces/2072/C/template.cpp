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
        int x;
        cin >> n;
        cin >> x;
        vector<int> res;
        int ones = 0;
        forn(i, ceil(log2(x)))
        {
            if (x & (1 << i))
            {
                ones++;
            }
            else
            {
                break;
            }
        }
        forn(i, min((int)pow(2, ones), n))
        {
            res.pb(i);
        }
        forsn(i, min((int)pow(2, ones), n), n)
        {
            res.pb(0);
        }
        if ((int)log2(res[n - 1]) != (int)log2(x))
        {
            res[n - 1] = x;
        }
        for (auto i : res)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}