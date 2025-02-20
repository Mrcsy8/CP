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
        vector<int> a(n);
        set<int> ot, ol;
        forn(i, n)
        {
            cin >> a[i];
            auto search = ol.find(a[i]);
            if (search == ol.end())
            {
                ot.insert({a[i]});
                ol.insert({a[i]});
            }
            else
            {
                ot.erase({a[i]});
            }
        }
        int l = 0, r = -1, streak = 0, maxi = 0;
        forn(i, n)
        {
            if (ot.find(a[i]) != ot.end())
            {
                streak++;
            }
            else
            {
                if (streak > maxi)
                {
                    l = i - streak;
                    r = i - 1;
                    maxi = streak;
                }
                streak = 0;
            }
        }
        if (streak > maxi)
        {
            l = a.size() - streak;
            r = a.size() - 1;
        }
        if (r == -1)
        {
            cout << "0\n";
        }
        else
        {
            cout << l + 1 << " " << r + 1 << "\n";
        }
    }
    return 0;
}