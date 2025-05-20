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
#define DBG(x) cout<<#x<<" = "<<(x)<<endl;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    forn(i,n)
    {
        cin >> a[i];
    }
    forn(i,n)
    {
        cin >> b[i];
    }
    int res = 0, j = 0;
    set<int> bag;
    forn(i,n)
    {
        if(j < n && a[j] == b[i])
        {
            do
            {
                j++;
            }
            while(j < n && bag.find(a[j]) != bag.end());
        }
        else
        {
            res++;
        }
        bag.insert(b[i]);
    }
    cout << res << "\n";
    return 0;
}
