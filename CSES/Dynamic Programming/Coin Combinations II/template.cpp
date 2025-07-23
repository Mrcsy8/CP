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

const ll MOD = 1e9 + 7;

int n, x;
vector<map<ll,ll>> dp;
vector<ll> c;
ll res = 0;

void solve(int r){
    ll sum = x;
    for(auto par : dp[r-1]){
        if(par.snd != 0){
            ll sum0 = par.fst;
            while(x > 0){
                dp[r][par.fst]++;
                sum0 -= c[r-1];
            }
            if(!sum0){
                res += par.snd % MOD;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    c.resize(n);
    dp.resize(n+1, map<ll,ll>());
    dp[0][x]++;
    forn(i,n){
        solve(i+1);
    }
    PRT(res);
    return 0;
}