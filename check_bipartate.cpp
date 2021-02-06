ll vis[N];

// vis[i]==0-->unvisited,vis[i]==1-->red,vis[i]==2-->blue
// no two connected components will have the same color
bool is_bipartite(ll i)
{
    vis[i]=1;
    queue<ll> q;
    q.push(i);
    bool ret=true;
    while(!q.empty())
    {
        ll x=q.front();
        for(auto it:v[x])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it]=3-vis[x];
            }
            else if(vis[it]==vis[x])
            {
                ret=false;
            }
        }
        q.pop();
    }
    return ret;
}

void bipartate()
{
    for(ll i=1;i<=n;i++)
    {
        vis[i]=0;
    }
    ll ans=1;
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i]) ans&=is_bipartite(i);
    }
    cout<<(ans?"YES":"NO")<<endl;
}