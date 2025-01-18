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
        string s;
        cin >> s;
        int ceros = 0, unos = 0;
        forn(i, n)
        {
            if (s[i] == '0')
                ceros++;
            else
                unos++;
        }
        if (unos % 4 == 0 && pow((unos / 4) - 1, 2) == ceros)
            cout << "Yes";
        else
            cout << "No";
        cout << "\n";
    }
    return 0;
}