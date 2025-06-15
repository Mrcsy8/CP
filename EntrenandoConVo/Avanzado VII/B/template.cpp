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
#define PNT(x) cout<<x<<"\n";

typedef long long ll;

ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    forn(i,n){
        cin >> a[i];
    }
    ll res = 1;
    vector<ll> part_gcd_l(n), part_gcd_r(n);
    ll g = a[0];
    part_gcd_l[0] = g;
    forsn(i,1,n){
        part_gcd_l[i] = gcd(g, a[i]);
        g = part_gcd_l[i];
    }
    g = a[n-1];
    part_gcd_r[n-1] = g;
    dforsn(i,0,n-1){
        part_gcd_r[i] = gcd(g, a[i]);
        g = part_gcd_r[i];
    }
    res = 1;
    forn(i,n){
        ll u;
        if(i - 1 < 0){
            u = part_gcd_r[1];
        }
        else {
            u = gcd(part_gcd_l[i-1],part_gcd_r[i+1]);
        }
        res /= gcd(res,u);
        res *= u;
    }
    PNT(res);
    return 0;
}