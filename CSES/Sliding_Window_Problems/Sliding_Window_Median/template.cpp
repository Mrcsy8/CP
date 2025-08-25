#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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

typedef tree<pair<ll,int>, null_type, less<pair<ll,int>>, rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<ll> x(n);
    forn(i,n){
        cin >> x[i];
    }
    vector<ll> res;
    ordered_set s;
    forn(i,k){
        s.insert(mp(x[i],i));
    }
    if(k%2){
        res.pb(s.find_by_order(k/2) -> fst);
        forsn(i,k,n){
            s.erase(mp(x[i-k],i-k));
            s.insert(mp(x[i],i));
            res.pb(s.find_by_order(k/2) -> fst);
        }
    }
    else{
        res.pb(min(s.find_by_order(k/2-1) -> fst, s.find_by_order(k/2) -> fst));
        forsn(i,k,n){
            s.erase(mp(x[i-k],i-k));
            s.insert(mp(x[i],i));
            res.pb(min(s.find_by_order(k/2 - 1) -> fst, s.find_by_order(k/2) -> fst));
        }
    }
    forn(i,res.size()){
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}
