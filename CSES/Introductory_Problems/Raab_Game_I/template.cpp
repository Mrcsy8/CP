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
        int n, a, b;
        cin >> n >> a >> b;
        int nemp = a + b;
        if(nemp > n || ((a == 0 || b == 0) && a+b != 0)){
            PRT("NO");
            continue;
        }
        PRT("YES");
        forn(i,n){
            cout << i+1 << " ";
        }
        cout << "\n";
        if(nemp == 0){
            forn(i,nemp){
                cout << i+1 << " ";
            }
        }
        else{
            forn(i,nemp){
                cout << ((i+a) % (nemp))+1 << " ";
            }
        }
        forsn(i,nemp,n){
            cout << i+1 << " ";
        }
        cout << "\n";
    }
    return 0;
}