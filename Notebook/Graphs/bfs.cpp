int N = 1e5;
vector<int> distance(N);
void bfs(int x){
    queue<int> q;
    vector<bool> visited(N);
    visited[x] = true;
    distance[x] = 0;
    q.push(x);
    while(!q.empty()){
        int s = q.front(); q.pop();
        for(auto u : adj[s]){
            if(visited[u]) continue;
            visited[u] = true;
            distance[u] = distance[s] + 1;
            q.push(u);
        }
    } 
}