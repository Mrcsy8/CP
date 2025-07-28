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
#define DBG(x) cout << #x << " = " << (x) << endl;
#define PRT(x) cout << x << "\n";

typedef long long ll;

int n, m;
vector<bool> visited;
int res = 0;
vector<vector<int>> adj;

void bfs(int x) {
    queue<int> q;
    visited[x] = true;
    q.push(x);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto u : adj[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            q.push(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    visited.resize(n * m, 0);
    adj.resize(n * m);
    vector<string> s(n);
    forn(i, n) {
        cin >> s[i];
    }
    forn(i, n) {
        forn(j, m) {
            if (s[i][j] == '.') {
                if (i - 1 >= 0 && s[i - 1][j] == '.') {
                    adj[i * m + j].pb((i - 1) * m + j);
                }
                if (j - 1 >= 0 && s[i][j - 1] == '.') {
                    adj[i * m + j].pb(i * m + (j - 1));
                }
                if (i + 1 < n && s[i + 1][j] == '.') {
                    adj[i * m + j].pb((i + 1) * m + j);
                }
                if (j + 1 < m && s[i][j + 1] == '.') {
                    adj[i * m + j].pb(i * m + (j + 1));
                }
            }
        }
    }

    forn(i, n) {
        forn(j, m) {
            if (s[i][j] == '.' && !visited[i * m + j]) {
                res++;
                bfs(i * m + j);
            }
        }
    }
    PRT(res);
    return 0;
}
