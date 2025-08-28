#include <bits/stdc++.h>
using namespace std;

#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
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

const int INF = INT_MAX;

char next_c(char c){
    if(c != 'z') return c+1;
    return 'a';
}

int g(string s, char l){
    int cont = 0;
    forn(i,s.length()) cont += (s[i] != l);
    return cont;
}

int f(string s, char l){
    if(s.length() == 1) return s[0] != l;
    int m = (int)s.size();
    int a = g(s.substr(0, m/2),l) + f(s.substr(m/2, m/2),next_c(l));
    int b = f(s.substr(0, m/2),next_c(l)) + g(s.substr(m/2, m/2),l);
    return min(a, b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        PRT(f(s,(char)('a')));
    }
    return 0;
}