#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int p=1,tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int camp,night,mid=0;
        scanf("%d %d",&camp,&night);
        int a[camp+2],hi=0,low=0,seg,sum;
        for(int i=0; i<camp+1; i++)
        {
            scanf("%d",&a[i]);
            hi+=a[i];
            if(a[i]>low)low=a[i];
        }
        while(mid!=low)
        {
            mid=(hi+low)/2;
            sum=0;
            seg=0;
            for(int i=0; i<camp+1; i++)
            {
                sum+=a[i];
                if(sum>mid)
                {
                    seg++;
                    sum=a[i];
                }
            }
            seg++;
//            cout<<hi<<" "<<mid<<" "<<low<<" "<<seg<<endl;
            if(seg<=night+1)hi=mid;
            else low=mid+1;
        }
        printf("Case %d: %d\n",p++,mid);
        sum=0;
        for (int j=0,i=0; i<=camp ; i++ )
        {
            sum+=a[i];
            if(sum>mid or night-j > camp-i)
            {
                printf("%d\n",sum-a[i]);
                j++;
                sum=a[i];
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
