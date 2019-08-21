#include<stdio.h>
int main()
{
    int i,j,x,test,a,n,s[7],res;
    s[1]=s[2]=s[3]=1;
    s[4]=s[5]=s[6]=1000;
    scanf("%d",&test);
    for(i=1;i<=test;i++)
    {
        scanf("%d",&a);
        s[1]=s[2]=s[3]=1;
        s[4]=s[5]=s[6]=1000;
        for(x=1;x<=a;x++)
        {
           for(j=1;j<=3;j++)
           {
               scanf("%d",&n);
               if(n>s[j]){
                s[j]=n;}
           }
           for(j=4;j<=6;j++)
           {
               scanf("%d",&n);
               if(n<s[j]){
                    s[j]=n;}
           }
 
        }
        if(s[4]>s[1]&&s[5]>s[2]&&s[6]>s[3])
        {
            res=(s[4]-s[1])*(s[5]-s[2])*(s[6]-s[3]);
           printf("Case %d: %d\n",i,res);}
        else printf("Case %d: 0\n",i);
    }
    return 0;
}
