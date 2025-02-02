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
        vector<int> w(n), h(n);
        forn(i, n)
        {
            cin >> w[i] >> h[i];
        }
        int max_w = 0, max_h = 0;
        forn(i, n)
        {
            max_w = max(max_w, w[i]);
            max_h = max(max_h, h[i]);
        }
        cout << (max_w + max_h) * 2 << "\n";
    }
    return 0;
}