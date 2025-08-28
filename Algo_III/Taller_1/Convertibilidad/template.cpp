#include <bits/stdc++.h>
using namespace std;

#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
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

vector<ll> f(ll x, ll y){
    if(x > y) return {};
    if(x == y) return {x};
    ll a = 2 * x, b = 10 * x + 1;
    vector<ll> av = f(a,y), bv = f(b,y);
    if(av.size() != 0){
        av.pb(x);
        return av;
    }
    if(bv.size() != 0){
        bv.pb(x);
        return bv;
    }
    return {};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x, y;
    cin >> x >> y;
    vector<ll> res = f(x,y);
    if(res.size() == 0){
        PRT("NO");
        return 0;
    }
    PRT("YES");
    reverse(ALL(res));
    PRT(res.size());
    forn(i,res.size()){
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}