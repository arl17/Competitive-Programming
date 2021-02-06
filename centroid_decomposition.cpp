set<ll> v[N];
ll sz[N];
ll parentcentroid[N];


void dfs(ll i,ll par)
{
    sz[i]=1;
    for(auto it:v[i])
    {
        if(it==par) continue;
        dfs(it,i);
        sz[i]+=sz[it];
    }

}


ll get_centroid(ll i,ll par,ll nodes)
{
    for(auto it:v[i])
    {
        if(it==par)
        {
            continue;
        }
        else if(sz[it]>nodes/2)
        {
            return get_centroid(it,i,nodes);
        }
    }
    return i;
}

void decompose(ll i,ll par)
{
    dfs(i,-1);
    ll node=get_centroid(i,i,sz[i]);
    parentcentroid[node]=par;
    for(auto it:v[node])
    {
        v[it].erase(node);
        decompose(it,node);
    }
    v[node].clear();
}
