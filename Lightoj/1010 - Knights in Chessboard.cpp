#include<bits/stdc++.h>
 
int main()
{
    int p=1,row,col,tc;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&row,&col);
        if(row==1||col==1)
        {
            if(row==1)printf("Case %d: %d\n",p++,col);
            else printf("Case %d: %d\n",p++,row);
            continue;
        }
        if(row==2||col==2)
        {
            int t=0,counti=0,a=0;
            while(t<row*col)
            {
                t++;
                counti++;
                a++;
                if(t%4==0)
                {
                    while(a--)t++;
                    a++;
                }
            }
            printf("Case %d: %d\n",p++,counti);
            continue;
        }
        if((row*col)&1)printf("Case %d: %d\n",p++,(row*col)/2+1);
        else printf("Case %d: %d\n",p++,(row*col)/2);
    }
    return 0;
}
