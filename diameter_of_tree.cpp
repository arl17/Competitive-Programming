ll x; // will give a node having maximum distance
ll max_dist;

void dfs(ll i,ll par,ll dist)
{
    if(dist>max_dist) 
    {
        max_dist=dist;
        x=i;
    }
    for(auto it:v[i])
    {
        if(it!=par) dfs(it,i,dist+1);
    }
}

ll diameter()
{
    max_dist=0;
    // starting from a random node
    dfs(1,1,1); 
    // starting from a node having max_dist from node 1
    dfs(x,x,1);
    ll d=max_dist;
    return d;

}
