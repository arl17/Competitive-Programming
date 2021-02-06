bool vis[N]; 
stack<ll> st;
vector<ll> order;
ll pos[N];

void toposort(ll i,ll par)
{
    vis[i]=true;
    for(auto it:v[i])
    {
        if(!vis[it]) toposort(it,i);
    }
    st.push(i);
}

bool check_cycle()
{
    ll cnt=0;
    while(!st.empty())
    {
        pos[st.top()]=cnt++;
        order.pb(st.top());
        st.pop();
    }
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i]) continue;
        for(auto it:v[i])
        {
            if(pos[i]>pos[it]) return true; // cycle exists
        }
    }
    return false;

}
