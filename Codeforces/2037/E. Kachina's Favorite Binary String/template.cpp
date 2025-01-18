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

int ask(int l, int r)
{
    int res;
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    cin >> res;
    return res;
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
        cout << "? 1 " << n << "\n";
        cout.flush();
        int res;
        cin >> res;
        if (res == 0)
        {
            cout << "! IMPOSSIBLE\n";
            cout.flush();
            continue;
        }
        if (n == 2 && res == 1)
        {
            cout << "! 01\n";
            cout.flush();
            continue;
        }
        vector<bool> a(n, 1);
        int l = 1, r = n, prev_res;
        while (r - l != 1)
        {
            r--;
            prev_res = res;
            res = ask(l, r);
            if (res == prev_res)
            {
                a[r] = 0;
            }
            else
            {
                a[r] = 1;
                break;
            }
        }
        r++;
        res = prev_res;
        while (r - l != 1)
        {
            l++;
            prev_res = res;
            res = ask(l, r);
            if (res == prev_res)
            {
                a[l - 2] = 1;
            }
            else
            {
                a[l - 2] = 0;
            }
        }
        if (res == 1)
        {
            a[l - 1] = 0;
        }
        else
        {
            a[l - 1] = 1;
        }
        cout << "! ";
        forn(i, n)
        {
            cout << a[i];
        }
        cout << "\n";
        cout.flush();
    }
    return 0;
}