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
#define PRT(x) cout<<x<<"\n";

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    map<ll,vector<int>> pos;
    forn(i,n){
        cin >> a[i];
        pos[a[i]].pb(i);
    }
    sort(ALL(a));
    forn(i,n){
        auto it = lower_bound(ALL(a), x-a[i]);
        if(it != a.end() && *it == x-a[i]){
            if(x - a[i] == a[i]){
                if(pos[a[i]].size() != 1){
                    cout << pos[a[i]][0]+1 << " " << pos[a[i]][1]+1 << "\n";
                    return 0;
                }
            }
            else{
                cout << pos[a[i]][0]+1 << " " << pos[*it][0]+1 << "\n";
                return 0;
            }
        }
    }
    PRT("IMPOSSIBLE");
    return 0;
}