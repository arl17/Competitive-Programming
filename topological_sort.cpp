bool vis[N];
stack<ll> st;


void toposort(ll i,ll par)
{
    vis[i]=true;
    for(auto it:v[i])
    {
        if(!vis[it]) toposort(it,i);
    }
    st.push(i);
}
