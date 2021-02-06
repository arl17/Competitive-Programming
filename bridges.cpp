// source: "https://codeforces.com/blog/entry/68138"


ll lev[N];
ll dp[N];
ll bridge;

void dfs(ll i,ll par)
{
    dp[i]=0;
    for(auto it:v[i])
    {
        if(lev[it]==0) // edge to a child
        {
            lev[it]=lev[i]+1;
            dfs(it,i);
            dp[i]+=dp[it];
        }
        else if(lev[it]<lev[i]) //back edge upwards
        {
            dp[i]++;
        } 
        else if(lev[it]>lev[i]) // back edge downwards
        {
            dp[i]--;
        }
    }

    // the parent of i edge isn't a back edge. subtract 1 to compensate 
    dp[i]--; 

    if(lev[i]>1 && dp[i]==0) // then the edge between i and its parent is a bridge
    {
        bridge++;
        cout<<i<<" "<<par<<endl;
    }
}

void find_bridges()
{
    lev[1]=1;
    bridge=0;
    memset(lev,0,sizeof lev);
    dfs(1,1);
    cout<<bridge<<endl;
}
