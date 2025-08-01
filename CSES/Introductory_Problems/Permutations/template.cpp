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
    if(n == 1){
        PRT(1);
        return 0;
    }
    if(n <= 3){
        PRT("NO SOLUTION");
        return 0;
    }
    if(n == 4){
        PRT("2 4 1 3");
        return 0;
    }
    for(int i = 1; i <= n; i += 2){
        cout << i << " ";
    }
    for(int i = 2; i <= n; i += 2){
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}