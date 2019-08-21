#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   m0d           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   lim           1000000000
using namespace std;
 
long long  mx,mn;
int trie[50000*35][3],sz;
 
void ins (int n)
{
    int a[35],node=0;
    for(int i=33;i>-1;i--){
        while(n){
            a[i]=n%2;
            n/=2;
            i--;
        }
        a[i]=0;
    }
    for(int i=0;i<34;i++){
        if(trie[node][a[i]]==-1) trie[node][a[i]]=sz++;
        node=trie[node][a[i]];
    }
}
 
long long q_mx(int x)
{
    int a[35],node=0;
    long long ret=0,b=pow(2,33);
    for(int i=33;i>-1;i--){
        while(x){
            a[i]=x%2;
            x/=2;
            i--;
        }
        a[i]=0;
    }
    for(int i=0;i<34;i++){
        if(a[i]==0){
            if(trie[node][1]!=-1){
                node=trie[node][1];
                ret+=b;
            }
            else node=trie[node][0];
        }
        else{
            if(trie[node][0]!=-1){
                node=trie[node][0];
                ret+=b;
            }
            else node=trie[node][1];
        }
        b/=2;
    }
    return ret;
}
 
long long q_mn(int x)
{
    int a[35],node=0;
    long long ret=0,b=pow(2,33);
    for(int i=33;i>-1;i--){
        while(x){
            a[i]=x%2;
            x/=2;
            i--;
        }
        a[i]=0;
    }
    for(int i=0;i<34;i++){
        if(a[i]==0){
            if(trie[node][0]!=-1){
                node=trie[node][0];
            }
            else node=trie[node][1],ret+=b;
        }
        else{
            if(trie[node][1]!=-1){
                node=trie[node][1];
            }
            else node=trie[node][0],ret+=b;
        }
        b/=2;
    }
    return ret;
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        mx=-1,mn=3000000000,sz=1;
        mm(trie,-1);
        ins(0);
        int n, x=0,num;
        cin>>n;
        while(n--){
            cin>>num;
            x^=num;
            mx=max(mx,q_mx(x));
            mn=min(mn,q_mn(x));
            ins(x);
        }
        printf("Case %d: %lld %lld\n",cas++,mx,mn);
    }
    return 0;
}
/*sample
 
*/
