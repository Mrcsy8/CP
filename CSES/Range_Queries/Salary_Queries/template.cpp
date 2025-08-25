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
    int n, q;
    cin >> n >> q;
    vector<ll> p(n);
    forn(i,n){
        cin >> p[i];
    }
    vector<tuple<char,ll,ll>> qu(q);
    forn(i,q){
        ll c, a, b;
        cin >> c >> a >> b;
        qu[i] = make_tuple(c,a,b);
    }
    map<pair<ll,ll>,int> m;
    dforn(i,q){
        if(get<0>(qu[i]) == '?'){
            m[mp(get<1>(qu[i]),get<2>(qu[i]))] = 0;
        }
        else{
            for(auto [a,b] : m){
                if()
            }
        }
    }
    return 0;
}