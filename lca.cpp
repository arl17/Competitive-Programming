// preprocessing=O(nlogn)
// lca=O(logn)

const int LOGN=20;
ll level[N];
ll dp[N][LOGN];
ll tin[N];
ll tout[N];
ll timer;
ll l;

void dfs0(ll i,ll par)
{
    level[i]=level[par]+1;
    tin[i]=timer++;
    dp[i][0]=par;
    for(ll j=1;j<=l;j++)
    {
        dp[i][j]=dp[dp[i][j-1]][j-1];
    }
    for(auto it:v[i])
    {
        if(it!=par) dfs0(it,i);
    }
    tout[i]=timer++;


}

bool is_ancestor(ll x,ll y)
{
    return tin[x]<=tout[y] && tout[x]>=tout[y];
}

ll lca(ll x,ll y)
{
    if(level[x]>level[y]) swap(x,y);
    if(is_ancestor(x,y))
        return x;
    if(is_ancestor(y,x))
        return y;
    for(ll i=l;i>=0;i--)
    {
        if(!is_ancestor(dp[x][i],y))
            x=dp[x][y];
    }
    return dp[x][0];
}


void preprocessing(ll root)
{
    memset(tin,0,sizeof tin);
    memset(tout,0,sizeof tout);
    timer=0;
    level[root]=0;
    l=ceil(log2(n));
    dfs0(root,root);

}
