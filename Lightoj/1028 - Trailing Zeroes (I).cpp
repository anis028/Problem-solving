#include<bits/stdc++.h>
 
using namespace std;
 
int prime[1000005];
vector<int> primes;
 
void seive(int n)
{
    prime[0]=prime[1]=1;
    for(int i=4;i<n;i+=2)prime[i]=1;
    for(int i=3;i*i<n;i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<n;j+=i) prime[j]=1;
        }
    }
    for(int i=2;i<n;i++)if(prime[i]==0)primes.push_back(i);
}
int main()
{
    seive(1000005);
    int tc,p=1,l=primes.size();
    scanf("%d",&tc);
    while(tc--)
    {
        long long int n,ans=1,x;
        scanf("%lld",&n);
        for(int i=0;i<l && primes[i]*primes[i]<=n;i++)
        {
            if(n%primes[i]==0)
            {
                x=0;
                while(n%primes[i]==0){
                    n/=primes[i];
                    x++;
                }
                ans*=(x+1);
            }
 
        }
        if(n>1)ans*=2;
        printf("Case %d: %lld\n",p++,ans-1);
    }
    return 0;
}
