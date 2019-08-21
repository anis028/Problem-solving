#include<bits/stdc++.h>
 
using namespace std;
 
struct a
{
    int num,div;
};
 
bool cmp(a x,a y)
{
    if(x.div==y.div)return x.num>y.num;
    else return x.div<y.div;
}
int main()
{
    int i,a[1005],j;
    for(i=0; i<1005; i++)a[i]=1;
    a[1]=1;
    for(i=2; i<1005; i++)
    {
        for(j=i; j<1005; j+=i)a[j]++;
    }
    struct a res[1005];
    for(i=1; i<1001; i++)
    {
        res[i].num=i;
        res[i].div=a[i];
    }
    sort (res,res+1001,cmp);
    int n,tc;
    i=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",i++,res[n].num);
    }
    return 0;
}
