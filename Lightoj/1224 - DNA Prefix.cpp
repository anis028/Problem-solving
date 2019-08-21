#include<bits/stdc++.h>
 
using namespace std;
 
#define mm(a,x) memset(a,x,sizeof(a))
 
int pore[2500000][4],shesh[2500000];
int main()
{
    //ios_base::sync_with_stdio(false);
    int tc,p=1;
    map<char,int>m;
    m['A']=0;
    m['C']=1;
    m['G']=2;
    m['T']=3;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,ans=0,sz=1;
        scanf("%d",&n);
        string s;
        mm(pore,-1);
        mm(shesh,0);
        while(n--)
        {
            cin>>s;
            int l=s.length();
            int node=0;
            for(int i=0 ; i<l ; i++)
            {
                if(pore[node][m[s[i]]]==-1)
                    pore[node][m[s[i]]]=sz++;
                node=pore[node][m[s[i]]];
                shesh[node]++;
                ans=max(ans,shesh[node]*(i+1));
            }
        }
        printf("Case %d: %d\n",p++,ans);
    }
    return 0;
}

