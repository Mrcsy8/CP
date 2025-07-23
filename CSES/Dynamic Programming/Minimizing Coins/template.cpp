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

const int INF = 1e6 + 1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> c(n), dp(x+1);
    forn(i,n){
        cin >> c[i];
    }
    dp[0] = 0;
    forsn(i,1,x+1){
        int mini = INF;
        forn(j,n){
            if(i - c[j] >= 0){
                mini = min(mini, dp[i - c[j]]);
            }
        }
        dp[i] = mini + 1;
    }
    if(dp[x] >= INF){
        PRT(-1);
    }
    else
    PRT(dp[x]);
    return 0;
}