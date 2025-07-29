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
    int n;
    ll x;
    cin >> n >> x;
    multiset<ll> p;
    vector<bool> visited(n,0);
    forn(i,n){
        ll in;
        cin >> in;
        p.insert(-in);
    }
    int res = 0;
    while(!p.empty()){
        auto it0 = p.begin();
        p.erase(it0);
        auto it1 = p.lower_bound(-x - *it0);
        if(it1 != p.end()){
            p.erase(it1);
        }
        res++;
    }
    PRT(res);
    return 0;
}