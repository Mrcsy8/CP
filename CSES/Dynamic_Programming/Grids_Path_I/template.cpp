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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<bool>> grid(n,vector<bool>(n));
    forn(i,n){
        string s;
        cin >> s;
        forn(j,n){
            grid[i][j] = (s[j] != '.');
        }
    }
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    dforn(i,n){
        dforn(j,n){
            if(grid[i][j]) continue;
            if(i+1 == n && j+1 == n){
                dp[i][j] = 1;
                continue;
            }
            if(i+1 == n){
                dp[i][j] = dp[i][j+1];
                continue;
            }
            if(j+1 == n){
                dp[i][j] = dp[i+1][j];
                continue;
            }
            dp[i][j] = (dp[i+1][j] + dp[i][j+1]) % MOD;
        }
    }
    PRT(dp[0][0]);

    return 0;
}