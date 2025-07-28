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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<ll> a(n);
        forn(i,n){
            cin >> a[i];
        }
        vector<ll> carga = a;
        vector<int> estacion;
        queue<int> usar;
        map<ll,int> estacion_kil;
        set<int> pilas_carga;
        forn(i,m){
            ll x;
            int r;
            cin >> x >> r;
            estacion_kil[x] = r;
            estacion.pb(x);
            pilas_carga.insert(r);
        }
        sort(ALL(estacion));
        priority_queue<pair<ll,int>> usar;
        map<int,ll> usar_fut;
        queue<int> usar_inf;

        ll rec = 0;
        forn(i,n){
            while(rec != estacion[i]){
                rec += min(usar.front().snd
            }
        }
    }
    return 0;
}