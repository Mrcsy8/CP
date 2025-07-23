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
 
vector<vector<int>> adj;
vector<bool> visited;
vector<bool> cats;
int n, m;
int res = 0;
 
void dfs(int s, int c){
	if(visited[s]) return;
	visited[s] = true;
	if(cats[s]){
		c++;
		if(c > m){
			return;
		}
	}
	else{
		c = 0;
	}
    int novis = 0;
	for(auto u : adj[s]){
		novis += !visited[u];
    }
    if(novis == 0){
        res++;
        return;
    }
	for(auto u : adj[s]){
		dfs(u,c);
	}
	return;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	visited.resize(n, false);
	adj.resize(n);
	cats.resize(n,false);
	vector<int> a(n);
	forn(i,n){
		bool a;
		cin >> a;
		cats[i] = a;
	}
	
	forn(i,n-1){
		int x, y;
		cin >> x >> y;
		x--;y--;
		adj[x].pb(y);
        adj[y].pb(x);
	}
	dfs(0,0);
	PRT(res);
	return 0;
}
	