#include<stdio.h>
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,r,x,y;
        long long int ans=1;
        scanf("%d %d",&n,&r);
        if(r>n)
        {
            printf("Case %d: 0\n",p++,ans);
            continue;
        }
        x=r;
        y=n;
        while(x--){ans*=y;y--;}
        x=r;
        y=n;
        while(x--)ans/=(x+1);
        x=r;
        y=n;
        while(x--){ans*=y;y--;}
        printf("Case %d: %lld\n",p++,ans);
    }
}
