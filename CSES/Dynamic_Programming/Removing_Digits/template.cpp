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

const int INF = 1e6 + 8;

vector<int> dp;

void solve(int m){
    if(m < 10){
        dp[m] = 1;
        return;
    }
    int mini = INF, cont = m;
    while(cont != 0){
        int d = cont % 10;
        if(d != 0) mini = min(mini, dp[m-d] + 1);
        cont /= 10;
    }
    dp[m] = mini;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    dp.resize(n);
    dp[0] = 0;
    forn(i,n){
        solve(i+1);
    }
    PRT(dp[n]);
    return 0;
}