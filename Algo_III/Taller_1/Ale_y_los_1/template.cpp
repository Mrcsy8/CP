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

ll n;

ll floor_pow_2(ll a){
    return 1LL << (63LL - __builtin_clzll(a));
}

bool f(ll x){
    if(floor_pow_2(x) == x) return (n & (1LL << (__builtin_clzll(x) - __builtin_clzll(n))));
    ll dif = x - floor_pow_2(x);
    return f(x - 2 * dif);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll l, r;
    cin >> n >> l >> r;
    if(n == 0){
        PRT(0);
        return 0;
    }
    int res = 0;
    for(ll i = l;i <= r;i++){
        res += f(i);
    }
    PRT(res);
    return 0;
}