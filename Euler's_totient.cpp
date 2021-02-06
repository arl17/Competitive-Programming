
ll phi(ll x)
{
    ll res=x;
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            while(x%i==0)
            {
                x=x/i;
            }
            res-=res/i;
        }
    }
    if(x>1) // if n itself is a prime number
    {
        res-=res/x;
    }
    return res;
}


void phi_1_to_n(ll n)
{
    ll phi[n+1];
    phi[0]=0;
    for(ll i=1;i<=n;i++)
    {
        phi[i]=i;
    }

    for(ll i=2;i<=n;i++)
    {
        if(phi[i]==i)
        {
            for(ll j=i;j<=n;j+=i)
            {
                phi[j]-=phi[j]/i;
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        cout<<phi[i]<<" ";
    }cout<<endl;
}
