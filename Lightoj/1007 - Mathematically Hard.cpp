#include<bits/stdc++.h>
 
using namespace std;
int mark[5000005];
long long phi[5000005];
void seivephi(int n)
{
    for(int i=1;i<n;i++)phi[i]=i;
    for(int i=2;i<n;i++)
    {
        if(!mark[i])
        {
            for(int j=i;j<n;j+=i)
            {
                mark[j]=1;
                phi[j]=phi[j]/i*(i-1);
            }
        }
        phi[i]=phi[i]*phi[i]+phi[i-1];
 
    }
}
int main()
{
    seivephi(5000005);
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("Case %d: %llu\n",p++,phi[b]-phi[a-1]);
    }
    return 0;
}
