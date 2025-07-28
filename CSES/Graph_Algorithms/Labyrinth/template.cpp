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

const int N = 1000, M = 1000;
int n, m;
vector<vector<int>> d(N, vector<int>(M,-1));
vector<vector<pair<int,int>>> p(N, vector<pair<int,int>>(M));
vector<vector<bool>> visited(N, vector<bool>(M,false));
vector<string> grid(N);

pair<int,int> f(int i, pair<int,int> u){
    if(i == 0){
        u.fst = u.fst+1;
    }
    if(i == 1){
        u.fst = u.fst-1;
    }
    if(i == 2){
        u.snd = u.snd+1;
    }
    if(i == 3){
        u.snd = u.snd-1;
    }
    return u;
}

void g(pair<int,int> u){
    if(u.fst == 0){
        if(u.snd == 1){
            cout << "R";
        }
        else{
            cout << "L";
        }
    }
    else{
        if(u.fst == 1){
            cout << "D";
        }
        else{
            cout << "U";
        }
    }
}

void bfs(pair<int,int> x){
    queue<pair<int,int>> q;
    visited[x.fst][x.snd] = true;
    d[x.fst][x.snd] = 0;
    p[x.fst][x.snd] = mp(-1,-1);
    q.push(x);
    while(!q.empty()){
        pair<int,int> s = q.front(); q.pop();
        forn(i,4){
            pair<int,int> u = f(i,s);
            if(min(u.fst,u.snd) < 0 || u.fst >= n || u.snd >= m || visited[u.fst][u.snd] || grid[u.fst][u.snd] == '#') continue;
            visited[u.fst][u.snd] = true;
            d[u.fst][u.snd] = d[s.fst][s.snd] + 1;
            p[u.fst][u.snd] = s;
            q.push(u);
        }
    } 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    pair<int,int> a, b;
    cin >> n >> m;
    forn(i,n){
        cin >> grid[i];
        forn(j,m){
            if(grid[i][j] == 'A'){
                a = mp(i,j);
            }
            if(grid[i][j] == 'B'){
                b = mp(i,j);
            }
        }
    }
    bfs(a);
    if (!visited[b.fst][b.snd]) {
        PRT("NO");
    }
    else{
        vector<pair<int,int>> path;
        for (pair<int,int> v = b; v != mp(-1,-1); v = p[v.fst][v.snd])
            path.push_back(v);
        reverse(ALL(path));
        PRT("YES");
        PRT(path.size() - 1);
        forn(i,path.size() - 1){
            pair<int,int> u = mp(path[i+1].fst - path[i].fst, path[i+1].snd - path[i].snd);
            g(u);
        }
    }
    return 0;
}