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

const int N = 1e5;

vector<int> adj[N];
int visited[N];

void dfs(int u){
    visited[u] = true;
    for(auto i : adj[u]){
        if(!visited[i]){
            dfs(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    forn(i,m){
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<int> connect;
    forn(i,n){
        if(!visited[i]){
            connect.pb(i);
            dfs(i);
        }
    }
    PRT(connect.size() - 1);
    forn(i,connect.size()-1){
        cout << connect[i] + 1 << " " << connect[i+1] + 1 << "\n";
    }
    return 0;
}