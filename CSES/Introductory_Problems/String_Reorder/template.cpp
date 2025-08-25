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

map<char,int> m;

char solve(char dist = -1){
    for(auto [k,v] : m){
        if(dist != k && v != 0){
            return k;
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    forn(i,s.size()){
        m[s[i]]++;
    }
    vector<char> res(s.size());
    forn(i,res.size()){
        if(i = 0){
            solve();
        }
        res[i] = solve(res[i-1]);
        if(res[i] == -1){
            PRT("NO");
            break;
        }
        m[res[i]]--;
    }
    forn(i,res.size()){
        cout << res[i];
    }
    cout << "\n";
    return 0;
}