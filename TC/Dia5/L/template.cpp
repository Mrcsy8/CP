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

int n, m, r, c;
ll x, y;
vector<vector<tuple<int,int,int>>> adj;
vector<string> grid;

void bfs(){
    queue<int> q;
    vector<bool> visited(n);
    vector<pair<int,int>> distance(n);
    visited[0] = true;
    distance[0] = mp(0,0);
    q.push();

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> r >> c;
    cin >> x >> y;
    grid.resize(n);
    adj.resize(n*n);
    forn(i,n){
        cin >> grid[i];
    }
    return 0;
}