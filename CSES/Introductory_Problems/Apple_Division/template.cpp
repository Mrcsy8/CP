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

const ll INF = 1e9 + 8;

int power(int a, int b){
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        int p = power(a, b / 2);
        return p * p;
    }
    else
    {
        int p = power(a, (b - 1) / 2);
        return p * p * a;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll res = INF;
    vector<ll> p(n);
    forn(i,n){
        cin >> p[i];
    }
    forn(i,power(2,n)){
        ll g1 = 0, g2 = 0;
        forn(j,n){
            if(((1 << j) & i) != 0){
                g1 += p[j];
            }
            else{
                g2 += p[j];
            }
        }
        res = min(res, abs(g1-g2));
    }
    PRT(res);
    return 0;
}