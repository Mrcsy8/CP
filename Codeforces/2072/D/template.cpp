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
        forn(i, n)
        {
            cin >> a[i];
        }
        int maxi = 0, l = 0, r = 0;
        int val;
        forn(i, n)
        {
            val = 0;
            forsn(j, i + 1, n)
            {
                if (a[i] > a[j])
                {
                    val++;
                }
                else if (a[i] < a[j])
                {
                    val--;
                }
                if (val > maxi)
                {
                    maxi = val;
                    l = i;
                    r = j;
                }
            }
        }
        cout << l + 1 << " " << r + 1 << "\n";
    }
    return 0;
}