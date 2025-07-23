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
        ll T;
        cin >> n;
        cin >> T;
        vector<ll> road(n);
        T--;
        forn(i,n){ 
            cin >> road[i];
        }
        priority_queue<ll> q;
        int best = 0;
        forn(i,n){
            if(T - (ll)i < 1) break;
            q.push({road[i] - (ll)i});
            while(!q.empty() && q.top() > T - (ll)i){
                q.pop();
            }
            best = max(best, (int)q.size());
        }   
        PRT(best);
        return 0;
    }