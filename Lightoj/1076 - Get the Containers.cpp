#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int vessel,container;
        scanf("%d %d",&vessel,&container);
 
        int a[vessel+1],hi=0,low=0,mid=0,sum,seg;
        for(int i=0; i<vessel; i++)
        {
            scanf("%d",&a[i]);
            hi+=a[i];
            low=max(low,a[i]);
        }
        while(mid!=low)
        {
            sum=0;
            seg=0;
            mid=low+(hi-low)/2;
            for(int i=0; i<vessel; i++)
            {
                sum+=a[i];
                if(sum>mid)
                {
                    seg++;
                    sum=a[i];
                }
            }
            seg++;
            if(seg<=container)hi=mid;
            else low=mid+1;
        }
        cout<<"Case "<<p++<<": "<<mid<<endl;
    }
 
    return 0;
}
