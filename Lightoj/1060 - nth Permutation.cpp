#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   loop(i,x,n)   for(int i=x;i<n;i++)
#define   pb            push_back
#define   pii           pair<int,int>
#define   imax          2147483647
#define   pcase(x)      printf("Case %d: ",x)
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   pf1(x)        printf("%d\n",x)
#define   pf2(x,y)      printf("%d %d\n",x,y)
#define   sf1(x)        scanf("%d",&x)
#define   sf2(x,y)      scanf("%d %d",&x,&y)
#define   fs            first
#define   sc            second
 
using namespace std;
typedef long long ll;
ll fact[22];
 
inline void cal()
{
    fact[0]=fact[1]=1;
    for(int i=2; i<20; i++) fact[i]=fact[i-1]*i;
}
 
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    cal();
    while(tc--)
    {
        int n,nai=0;
        string s,ans="";
        cin>>s>>n;
        int l=s.length();
        int nisi=0,freq[29];
        memset(freq,0,sizeof freq);
        for(int i=0; i<l; i++) freq[s[i]-'a']++;
        ll sum;
        while(nisi!=l)
        {
            for(int i=0; i<26; i++)
            {
                if(freq[i]==0) continue;
                freq[i]--;
                sum=fact[l-1-nisi];
                for(int j=0; j<26; j++)
                {
                    if(freq[j]==0) continue;
                    sum/=fact[freq[j]];
                }
                if(sum>=n)
                {
                    ans+=(i+'a');
                    nisi++;
                    break;
                }
                else
                {
                    freq[i]++;
                    n-=sum;
                }
            }
            if(nisi==0)
            {
                nai=1;
                break;
            }
        }
        printf("Case %d: ",cas++);
        if(nai) printf("Impossible\n");
        else
        {
            cout<<ans<<endl;
        }
    }
    return 0;
}
/*sample
 
*/
