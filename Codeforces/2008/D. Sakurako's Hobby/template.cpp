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
        vector<int> p(n);
        forn(i, n)
        {
            cin >> p[i];
        }
        string s;
        cin >> s;
        vector<int> F(n, -1);
        forn(i, n)
        {
            if (F[i] != -1)
            {
                continue;
            }
            vector<bool> found(n, 0);
            vector<int> encon;
            int j = i, cont = 0;
            encon.pb(j);
            while (!found[j])
            {
                if (s[j] == '0')
                    cont++;
                found[j] = true;
                encon.pb(j);
                j = p[j] - 1;
            }
            for (auto k : encon)
            {
                F[k] = cont;
            }
        }
        for (auto i : F)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}