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
    int n, q;
    cin >> n >> q;
    vector<ll> s(n);
    forn(i,n){
        cin >> s[i];
    }
    vector<ll> pref(n+1);
    pref[0] = 0;
    forsn(i,1,n+1){
        pref[i] = pref[i-1] + s[i-1];
    }
    forn(i,q){
        int a, b;
        cin >> a >> b;
        a--;b--;
        PRT(pref[b+1] - pref[a]);
    }
    return 0;
}