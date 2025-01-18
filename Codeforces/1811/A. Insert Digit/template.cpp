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
        int d;
        int n;
        string s;
        cin >> n >> d;
        cin >> s;
        bool use = false;
        forn(i, n)
        {
            if (!use && d > s[i] - '0')
            {
                cout << d;
                use = true;
            }
            cout << s[i];
        }
        if (!use)
        {
            cout << d;
        }
        cout << "\n";
    }
    return 0;
}