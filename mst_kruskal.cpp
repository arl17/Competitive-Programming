// for finding the minimum/maximum possible sum of a spanning tree of a graph

//Running time = O(mlogn)


/* for maximum spanning tree replace all weights with negative sign
 and apply the same algorithm*/



vector<pair<ll,pii>> edge;// edge.first=wt of edge, (edge.second.first,edge.second.second)=nodes
ll par[N];

ll root(ll x)
{
    while(par[x]!=x)
    {
        x=par[x];
    }
    return x;
}

void union1(ll x,ll y)
{
    par[root(x)]=y;
}


ll kruskal() // returns the min weight
{
    ll min_cost=0;
    for(auto it:edge)
    {
        ll x=it.second.first;
        ll y=it.second.second;
        ll cost=it.first;
        if(root(x)!=root(y))
        {
            min_cost+=cost;
            union1(x,y);
        }
    }
    return min_cost;
}

void mst()
{
    sort(edge.begin(),edge.end()); // sort wrt the weight

    for(ll i=1;i<=n;i++) //initialising root to itself
    {
        par[i]=i;
    }

    cout<<kruskal()<<endl;
}
