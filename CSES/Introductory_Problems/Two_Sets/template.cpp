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
    cin >> n;
    int gauss = n*(n+1)/2;
    if(gauss%2){
        PRT("NO");
    }
    else{
        PRT("YES");
        if(n % 2){
            set<int> g;
            int sum = 0, i = 1;
            while(sum * 2 != gauss){
                g.insert(i);
                g.insert(n-i);
                sum += n;
                i++;
            }
            PRT(g.size());
            for(auto j : g){
                cout << j << " ";
            }
            cout << "\n";
            PRT(n - g.size());
            forn(j,n){
                if(g.find(j+1) == g.end()){
                    cout << j+1 << " ";
                }
            }
            cout << "\n";
        }
        else{
            int i = 1;
            bool step = false;
            vector<int> g1, g2;
            while(i <= n){
                g1.pb(i);
                if(step){
                    i += 1;
                }
                else{
                    i += 3;
                }
                step = !step;
            }
            i = 2;
            step = true;
            while(i <= n){
                g2.pb(i);
                if(step){
                    i += 1;
                }
                else{
                    i += 3;
                }
                step = !step;
            }
            PRT(g1.size());
            forn(j,g1.size()){
                cout << g1[j] << " ";
            }
            cout << "\n";
            PRT(g2.size());
            forn(j,g2.size()){
                cout << g2[j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// 1 4 5 8
// 2 3 6 7