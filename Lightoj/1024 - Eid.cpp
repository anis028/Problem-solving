#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
 
using namespace std;
 
int flag[10003],prime[10000];
 
void sieve()
{
    int ind =0;
    for(int i=4; i<=10000; i+=2) flag[i]=1;
    for(int i=3; i*i<=10000; i+=2)
    {
        if(!flag[i])
            for(int j=i*i,k=i<<1; j<=10000; j+=k) flag[j]=1;
    }
    for(int i=2; i<=10000; i++)
        if(!flag[i])
            prime[ind++]=i;
}
 
string multiply( string a, int b ) {
    // a contains the biginteger in reversed form
    int carry = 0;
    for( int i = 0; i < a.size(); i++ ) {
        carry += (a[i] - 48) * b;
        a[i] = ( carry % 10 + 48 );
        carry /= 10;
    }
    while( carry ) {
        a += ( carry % 10 + 48 );
        carry /= 10;
    }
    return a;
}
 
int main()
{
 
    sieve();
    int tc,p=1,ara[10003];
    scanf("%d",&tc);
    while(tc--)
    {
        int n;
        for(int i=0;i<10003;i++) ara[i]=0;
        scanf("%d",&n);
        int a[n+2];
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            int x=0,num=a[i],cnt;
            while(prime[x]*prime[x]<=num)
            {
                cnt=0;
                while(num%prime[x]==0)
                {
                    num/=prime[x];
                    cnt++;
                }
                ara[prime[x]]=max(ara[prime[x]],cnt);
                x++;
            }
            if(num>1) ara[num]=max(ara[num],1);
        }
        string ans="1";
        for(int i=1; i<=10000; i++)
        {
            if(ara[i]!=0)
            {
                while(ara[i]--) ans=multiply(ans,i);
            }
        }
        printf("Case %d: ",p++);
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
 
    return 0;
}
