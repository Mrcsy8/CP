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
        int a[4];
        forn(i, 4)
        {
            cin >> a[i];
        }
        multiset<int> sums;
        sums.insert({a[0] + a[1]});
        sums.insert({a[2] - a[1]});
        sums.insert({a[3] - a[2]});
        int maxi = 0;
        for (auto &i : sums)
        {
            maxi = max(maxi, (int)sums.count(i));
        }
        cout << maxi << "\n";
    }
    return 0;
}