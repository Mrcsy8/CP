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

const int N = 2e5;

vector<int> ady[N];
int sons[N];

int calc(int x){
    if(sons[x] != -1){
        return sons[x];
    }
    if(ady[x].size() == 0){
        sons[x] = 0;
        return sons[x];
    }
    int res = 0;
    for(auto u : ady[x]){
        res += calc(u) + 1;
    }
    sons[x] = res;
    return sons[x];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(sons, -1, sizeof(sons));
    int n;
    cin >> n;
    forn(i,n-1){
        int s;
        cin >> s;
        s--;
        ady[s].pb(i+1);
    }
    forn(i,n){
        calc(i);
    }
    forn(i,n){
        cout << sons[i] << " ";
    }
    cout << "\n";
    return 0;
}