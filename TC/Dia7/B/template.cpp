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

        bool check(ll k,ll a, ll b, ll c){
            return (b-k)*(b-k) < 4 * a * c;
        }

        int main(){
            ios::sync_with_stdio(0);
            cin.tie(0);
            int t;
            cin >> t;
            while(t--){
                int n, m;
                cin >> n >> m;
                vector<ll> rect(n);
                vector<tuple<ll,ll,ll>> par(m);
                forn(i,n){
                    cin >> rect[i];
                }
                sort(ALL(rect));
                forn(i,m){
                    ll x, y, z;
                    cin >> x >> y >> z;
                    par[i] = make_tuple(x,y,z);
                    auto [a, b, c] = par[i];
                    if(c<=0){
                        PRT("NO");
                        continue;
                    }
                    auto it=lower_bound(ALL(rect), b);
                    if(it != rect.end() && check(*it,a,b,c)){
                        PRT("YES");
                        PRT(*it);
                        continue;
                    }
                    else if(it != rect.begin() && check(*prev(it),a,b,c)){
                        PRT("YES");
                        PRT(*prev(it));
                        continue;
                    }
                    else if(it != prev(rect.end()) && it != rect.end() && check(*next(it),a,b,c)){
                        PRT("YES");
                        PRT(*next(it));
                        continue;
                    }
                    PRT("NO");
                }	
                cout << "\n";
            }
            
            return 0;
        }