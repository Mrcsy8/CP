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

const int N = 500;
const ll INF = 1e18 + 8;
ll g[N][N];
int n, m, q;

void floyd(){ // O(n^3) . Replaces g with min distances
	forn(k,n)forn(i,n)if(g[i][k]<INF)forn(j,n)if(g[k][j]<INF)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}
bool inNegCycle(int v){return g[v][v]<0;}
bool hasNegCycle(int a, int b){ // true iff there's neg cycle in between
	forn(i,n)if(g[a][i]<INF&&g[i][b]<INF&&g[i][i]<0)return true;
	return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(&g[0][0], &g[0][0] + N*N, INF);
    forn(i,N){
        g[i][i] = 0;
    }
    cin >> n >> m >> q;
    forn(i,m){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a][b] = min(g[a][b],c);
        g[b][a] = min(g[b][a],c); 
    }
    floyd();
    forn(i,q){
        int a, b;
        cin >> a >> b;
        a--;b--;
        if(g[a][b] == INF){
            PRT(-1);
        }
        else{
            PRT(g[a][b]);
        }
    }

    return 0;
}