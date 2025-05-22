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
    map<int,vector<int>> nums;
    
    forn(i,n)
    {
        int input;
        cin >> input;
        nums[input].pb(i);
    }
    ll res = 0;
    for(auto pair : nums)
    {
        if(!pair.snd.empty())
        {
            res -= powl(pair.snd[0], 2);
            forn(j,pair.snd.size()-1)
            {
                res -= powl(pair.snd[j+1] - pair.snd[j] - 1,2);
            }
            res -= powl(n - pair.snd[pair.snd.size()-1]-1,2);
            res += powl(n,2);
        }
    }
    cout << (double)res/powl(n,2) << "\n";
    return 0;
}