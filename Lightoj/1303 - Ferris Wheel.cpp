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
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        printf("Case %d: ",p++);
        int n,m;
        scanf("%d %d",&n,&m);
        int chorse[n+1][m+1],ase[m+1],x=0,y=n*m;
        vector<int>line;
        mm(ase,0);
        mm(chorse,0);
        for(int i=1; i<=n; i++) line.pb(i);
        int wheel_no=1,i,ind=0,cnt=0,utse;
        while(1)
        {
            if(x==y) {cnt+=m;break;}
            if(wheel_no==m+1) wheel_no=1;
 
            if(ase[wheel_no]!=0)
                if(chorse[ase[wheel_no]][0]!=m)
                    line.pb(ase[wheel_no]);
            utse=0;
 
            for(i=0; i<line.size(); i++)
            {
                if(chorse[line[i]][wheel_no]==0)
                {
                    utse=1;
                    chorse[line[i]][wheel_no]=1;
                    x++;
                    ase[wheel_no]=line[i];
                    line.erase(line.begin()+i);
                    ind++;
                    break;
                }
            }
            if(!utse and i==line.size()) ase[wheel_no]=0;
            wheel_no++;
            cnt++;
        }
        printf("%d\n",5*cnt);
    }
    return 0;
}
/*sample
 
*/
