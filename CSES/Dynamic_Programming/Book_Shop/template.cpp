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

int n, x;
vector<pair<ll, vector<bool>>> dp;
vector<ll> h, s;

void solve(int m){
    ll maxi = 0;
    vector<bool> maxi_used(n,0);
    forn(i,n){
        if(m >= h[i] && !dp[m - h[i]].snd[i]){
            if(maxi < dp[m - h[i]].fst + s[i]){
                maxi = dp[m - h[i]].fst + s[i];
                maxi_used = dp[m - h[i]].snd;
                maxi_used[i] = true;
            }
        }
    }
    if(maxi > dp[m-1].fst){
        dp[m] = mp(maxi,maxi_used);
    }
    else{
        dp[m] = dp[m-1];
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    dp.resize(x+1, mp(0,vector<bool>(n,0)));
    h.resize(n);
    s.resize(n);
    forn(i,n){
        cin >> h[i];
    }
    forn(i,n){
        cin >> s[i];
    }
    forn(i,x){
        solve(i+1);
    }
    PRT(dp[x].fst);
    return 0;
}