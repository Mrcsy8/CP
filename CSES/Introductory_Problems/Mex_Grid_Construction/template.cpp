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
    vector<set<int>> v(n);
    vector<vector<int>> grid(n, vector<int>(n));
    forn(i,n){
        set<int> h;
        forn(k,i + n + 1){
            h.insert(k);
        }
        forn(j,n){
            if(i == 0){
                forn(k,n + n + 1){
                    v[j].insert(k);
                }
            }
            set<int> hv;
            for(auto e : h){
                if(v[j].find(e) != v[j].end()){
                    hv.insert(e);
                }
            }
            grid[i][j] = *hv.begin();
            v[j].erase(grid[i][j]);
            h.erase(grid[i][j]);
        }
    }
    forn(i,n){
        forn(j,n){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}