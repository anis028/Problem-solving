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
 
using namespace std;
 
int nxt[100007][54],shesh[100007];
 
 
int main()
{
    int tc,p=1,node;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,l,sz=0;
        scanf("%d",&n);
        getchar();
        mm(nxt,-1);
        mm(shesh,0);
        char x[10007];
        while(n--)
        {
            gets(x);
            string word;
            word=x;
            if(word.length()>2)sort(word.begin()+1,word.end()-1);
            node=0;
            for(int i=0; i<word.length(); i++)
            {
                if(isupper(word[i]))
                {
                    if(nxt[node][word[i]-'A']==-1)
                        nxt[node][word[i]-'A']=++sz;
                    node=nxt[node][word[i]-'A'];
                }
                else
                {
                    if(nxt[node][26+word[i]-'a']==-1)
                        nxt[node][26+word[i]-'a']=++sz;
                    node=nxt[node][26+word[i]-'a'];
                }
            }
            ++shesh[node];
        }
        scanf("%d",&n);
        getchar();
        printf("Case %d:\n",p++);
        while(n--)
        {
            long long int ans=1;
            gets(x);
            string line,a;
            line=x;
            stringstream ss(line);
            while(ss>>a)
            {
                if(a.length()>2)sort(a.begin()+1,a.end()-1);
                node=0;
                for(int k=0; k<a.length(); k++)
                {
                    if(isupper(a[k])){
                        if(nxt[node][a[k]-'A']==-1) {ans=0;break;}
                        else node=nxt[node][a[k]-'A'];
                    }
                    else{
                        if(nxt[node][26+a[k]-'a']==-1) {ans=0;break;}
                        else node=nxt[node][26+a[k]-'a'];
                    }
                }
                ans*=shesh[node];
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
/*sample
 
*/
