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

vector<set<int>> adj(N);

bool visited[N];

int start, siz = 0;
deque<int> road;

bool found = false;

void dfs(int x){
    visited[x] = true;
    road.pb(x);siz++;
    for(auto u : adj[x]){
        if(found) break;
        if(road.size() < 2 || road[road.size()-2] != u){
            if(visited[u]){
                road.pb(u);siz++;
                while(road.front() != u){
                    road.pop_front();siz--;
                }
                found = true;
                break;
            }
            dfs(u);
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
        adj[a].insert(b);
        adj[b].insert(a);
    }
    
    bool check = true;
    while(check){
        check = false;
        forn(i,n){
            if(adj[i].size() == 1){
                int u = *adj[i].begin();
                adj[u].erase(i);
                adj[i].erase(u);
                check = true;
            }
        }
    }
    forn(i,n){
        if(adj[i].size()){
            dfs(i);
            PRT(siz);
            while(!road.empty()){
                cout << road.front() + 1 << " ";
                road.pop_front();
            }
            cout << "\n";
            return 0;
        }
    }
    PRT("IMPOSSIBLE");
    return 0;
}