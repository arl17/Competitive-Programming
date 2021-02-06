bool prime[1000000];

void SieveOfEratosthenes(ll n) 
{ 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
         
        if (prime[p] == true) 
        {  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
} 

void sieve(ll n)
{
    for(ll i=1;i<=n;i++)
    {
        prime[i]=true;
    }
    SieveOfEratosthenes(n);
}