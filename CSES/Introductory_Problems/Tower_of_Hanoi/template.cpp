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

vector<pair<int,int>> res;

void solve(int n, int b, int m, int e){
    if(n == 1){
        res.pb(mp(b,e));
        return;
    }
    solve(n-1,b,e,m);
    res.pb(mp(b,e));
    solve(n-1,m,b,e);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n,1,2,3);
    PRT(res.size());
    forn(i,res.size()){
        cout << res[i].fst << " " << res[i].snd << "\n";
    }
    return 0;
}