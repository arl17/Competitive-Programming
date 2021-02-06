ll sz[N];

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


ll get_centroid(ll i,ll par)
{
    for(auto it:v[i])
    {
        if(it==par)
        {
            continue;
        }
        else if(sz[it]>n/2)
        {
            return get_centroid(it,i);
        }
    }
    return i;
}
