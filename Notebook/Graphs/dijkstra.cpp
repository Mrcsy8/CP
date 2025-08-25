vector<pair<int,ll>> g[N];  // u->[(v,cost)]
ll dist[N];
void dijkstra(int x){
    memset(dist,-1,sizeof(dist));
    priority_queue<pair<ll,int> > q;
    dist[x]=0;q.push({0,x});
    while(!q.empty()){
        x=q.top().snd;ll c=-q.top().fst;q.pop();
        if(dist[x]!=c)continue;
        forn(i,g[x].size()){
            int y=g[x][i].fst; ll c=g[x][i].snd;
            if(dist[y]<0||dist[x]+c<dist[y])
                dist[y]=dist[x]+c,q.push({-dist[y],y});
        }
    }
}