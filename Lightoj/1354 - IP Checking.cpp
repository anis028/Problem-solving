#include<stdio.h>
#include<math.h>
 
int dec_to_bin(int n1)
{
     int base=1,i=0,m;
        while(n1>0)
        {
            m=n1%2;
            i+=m*base;
            n1/=2;
            base=base*10;
        }
        return i;
}
 
int main()
{
    int tc,n1,n2,n3,n4,b1,b2,b3,b4,c=1,i=0,m;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d.%d.%d.%d",&n1,&n2,&n3,&n4);
        scanf("%d.%d.%d.%d",&b1,&b2,&b3,&b4);
 
        int flag=1;
        if(dec_to_bin(n1)!=b1) flag=0;
        if(dec_to_bin(n2)!=b2) flag=0;
        if(dec_to_bin(n3)!=b3) flag=0;
        if(dec_to_bin(n4)!=b4) flag=0;
        if(flag)
        {printf("Case %d: Yes\n",c++);}
        else
         {printf("Case %d: No\n",c++);}
 
    }
    return 0;
}
