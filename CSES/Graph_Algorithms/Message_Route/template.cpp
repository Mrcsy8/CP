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
int d[N], p[N];
bool visited[N];
void bfs(int x){
    queue<int> q;
    visited[x] = true;
    d[x] = 0;
    p[x] = -1;
    q.push(x);
    while(!q.empty()){
        int s = q.front(); 
        q.pop();
        for(int u : adj[s]){
            if(visited[u]) continue;
            visited[u] = true;
            d[u] = d[s] + 1;
            p[u] = s;
            q.push(u);
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
    bfs(0);
    if (!visited[n-1]) {
        cout << "IMPOSSIBLE";
    }
    else{
        vector<int> path;
        for (int v = n-1; v != -1; v = p[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        PRT(path.size());
        forn(i,path.size()){
            cout << path[i] + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}