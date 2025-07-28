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
    string s;
    cin >> s;
    map<char,int> m;
    forn(i,s.length()){
        m[s[i]]++;
    }
    bool check = false;
    char imp;
    string pal;
    for(auto par : m){
        if(par.snd % 2){
            if(check){
                PRT("NO SOLUTION");
                return 0;
            }
            imp = par.fst;
            check = true;
        }
        while(par.snd > 1){
            par.snd -= 2;
            pal += par.fst;
        }
    }
    forn(i,pal.length()){
        cout << pal[i];
    }
    if(check){
        cout << imp;
    }
    dforn(i,pal.length()){
        cout << pal[i];
    }
    cout << "\n";
    return 0;
}