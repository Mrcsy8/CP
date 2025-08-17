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
    cin >> n;
    vector<pair<ll,ll>> movies(n);
    forn(i,n){
        ll a, b;
        cin >> a >> b;
        movies[i] = mp(b,a);
    }
    sort(ALL(movies));
    ll cur = 0, res = 0;
    forn(i,n){
        if(movies[i].snd >= cur){
            cur = movies[i].fst;
            res++;
        }
    }
    PRT(res);
    return 0;
}