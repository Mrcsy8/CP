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

if (!used[u]) {
    cout << "No path!";
}
else{
    vector<int> path; // restore path to u
    for (int v = u; v != -1; v = p[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
}
