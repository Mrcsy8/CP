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
    vector<vector<int>> color(48, vector<int>(143,0));
    forn(i,48){
        forn(j,143){
            color[i][j] = 0;
        }
    }
    int n;
    cin >> n;
    int cont = 1;
    forn(i,n){
        forn(j,n){
            if(color[i/21][j/7] == 0){
                color[i/21][j/7] = cont;
                cont++;
            }
            cout << color[i/21][j/7] << " ";
        }
        cout << "\n";
    }
    return 0;
}