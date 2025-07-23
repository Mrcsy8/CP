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
    vector<int> pref(s.length()+1);
    pref[0] = 0;
    forsn(i,1,s.length() +1){
        pref[i] = pref[i-1] + (s[i-1] == 'a');
    }
    int best = 0;
    forn(l,s.length()+1){
        forsn(r,l,s.length()+1){
            best = max(best, pref[l] + pref[s.length()] - pref[r] + (r - l) - (pref[r] - pref[l]));
        }
    }
    PRT(best);
    return 0;
}