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
        int n, m;
        cin >> n >> m;
        vector<int> nums(2000, -1);
        forn(i, n)
        {
            forn(j, m)
            {
                int input;
                cin >> input;
                nums[input] = i;
            }
        }
        bool res = true;
        forn(i, (n * m))
        {
            if (nums[i] != nums[i % n])
            {
                res = false;
                break;
            }
        }
        if (res)
        {
            forn(i, n)
            {
                cout << nums[i] + 1 << " ";
            }
        }
        else
        {
            cout << "-1";
        }
        cout << "\n";
    }
    return 0;
}