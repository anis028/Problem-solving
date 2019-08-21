#include<stdio.h>
#include<math.h>

int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        long long int n,row,col,root,temp;
        scanf("%lld",&n);
        if(n==1)
        {
            printf("Case %d: 1 1\n",p++);
            continue;
        }
        root=pow(n,0.5);
        temp=(root*root)+root+1;
        if((root*root)==n && (root&1))
        {
            printf("Case %d: 1 %lld\n",p++,root);
            continue;
        }
        if((root*root)==n && !(root&1))
        {
            printf("Case %d: %lld 1\n",p++,root);
            continue;
        }
        if(n==temp) printf("Case %d: %lld %lld\n",p++,(root+1),(root+1));
        if(root&1)
        {
            if(n<temp)
            {
                row= (root+1);
                col= root+1-temp+n;
                printf("Case %d: %lld %lld\n",p++,col,row);
            }
            else if(n>temp)
            {
                col= (root+1);
                row= root+1+temp-n;
                printf("Case %d: %lld %lld\n",p++,col,row);
            }
        }
        else
        {
            if(n>temp)
            {
                row= (root+1);
                col= root+1+temp-n;
                printf("Case %d: %lld %lld\n",p++,col,row);
            }
            else if(n<temp)
            {
                col= (root+1);
                row= root+1-temp+n;
                printf("Case %d: %lld %lld\n",p++,col,row);
            }
        }

    }
    return 0;
}
