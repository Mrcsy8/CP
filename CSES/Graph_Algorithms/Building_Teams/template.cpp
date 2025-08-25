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
int n, m;
vector<int> adj[N];
int teams[N];
bool poss = true;
void bfs(int x){
    queue<int> q;
    teams[x] = 0;
    q.push(x);
    while(!q.empty()){
        int s = q.front(); 
        q.pop();
        for(int u : adj[s]){
            if(teams[u] == -1){
                teams[u] = !teams[s];
                q.push(u);
            }
            else if(teams[u] == teams[s]){
                poss = false;
                break;
            }
        }
        if(!poss) break;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    forn(i,m){
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    fill(teams, teams + N, -1);
    forn(i,n){
        if(teams[i] == -1){
            bfs(i);
        }
    }
    
    if(!poss){
        PRT("IMPOSSIBLE");
    }
    else{
        forn(i,n){
            cout << teams[i] + 1 << " ";
        }
        cout << "\n";
    }
    
    return 0;
}