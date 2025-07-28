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
vector<ll> dp;
vector<ll> c;

void solve(int r){
    for(int i = c[r]; i <= x; i++){
        dp[i] = (dp [i] + dp[i - c[r]]) % MOD; 
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    c.resize(n);
    forn(i,n){
        cin >> c[i];
    }
    dp.resize(x+1,0);
    dp[0] = 1;
    forn(i,n){
        solve(i);
    }
    PRT(dp[x]);
    return 0;
}