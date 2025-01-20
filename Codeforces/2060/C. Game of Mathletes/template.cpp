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
        int n, k;
        cin >> n >> k;
        multiset<int> x;
        forn(i, n)
        {
            int input;
            cin >> input;
            x.insert(input);
        }
        int score = 0;
        forsn(i, 1, k / 2 + 1)
        {
            if (i == k - i)
            {
                score += min(x.count({i}), x.count({k - i})) / 2;
            }
            else
            {
                score += min(x.count({i}), x.count({k - i}));
            }
        }
        cout << score << "\n";
    }
    return 0;
}