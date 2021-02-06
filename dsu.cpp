
ll par[N];
ll sz[N];

ll find_parent(ll i)
{
    if(parent[parent[i]]!=parent[i])
    {
        parent[i]=find_parent(parent[i]);
    }
    return parent[i];
}

void union_nodes(ll a,ll b)
{
    ll parent_a=find_parent(a);
    ll parent_b=find_parent(b);

    if(parent_a==parent_b) return ;
    if(sz[parent_a]>=sz[parent_b]) swap(parent_a,parent_b);

    sz[parent_b]+=sz[parent_a];
    parent[parent_a]=parent_b;

}

void init_dsu(ll n)   // initialise dsu
{
    for(ll i=0;i<=n;i++)
    {
        par[i]=i;
        sz[i]=1;
    }
}
