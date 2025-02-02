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

bool desc(pair<ll, int> &a, pair<ll, int> &b)
{
    if (a.fst == b.fst)
    {
        return a.snd < b.snd;
    }
    return a.fst > b.fst;
}

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
        vector<pair<ll, int>> a(n);
        forn(i, n)
        {
            cin >> a[i].fst;
            a[i].snd = i;
        }
        sort(ALL(a), desc);
        int res = INT32_MAX;
        forn(i, n)
        {
            res = min(res, i + a[i].snd);
        }
        cout << res << "\n";
    }
    return 0;
}