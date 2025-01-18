#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = a; i < b; i++)

int n, m;
vector<int> cats;
vector<vector<int>> adj;
vector<bool> visited;
int sum = 0;

void dfs(int node, int k)
{
    if(visited[node]) return;
    if(cats[node])
    {
        if(k < m)
        {
            k++;
        }
        else return;
    }
    else k = 0;
    visited[node] = 1;
    if(adj[node].size() == 1 && node != 0)
    {
        sum++;
        return;
    }
    for(auto i : adj[node])
    {
        dfs(i, k);
    }

}

int main()
{
    cin >> n >> m;

    adj.resize(n);
    visited.resize(n);

    REP(i, 0, n)
    {
        int a;
        cin >> a;
        cats.push_back(a);
    }
    REP(i, 1, n)
    {
        int x, y;
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    dfs(0, 0);

    cout << sum << endl;

    return 0;
}