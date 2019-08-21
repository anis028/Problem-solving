#include<stdio.h>
#include<math.h>
int main()
{
    int tc,c,m,i,kase=1;
    long long int n;
    scanf("%d",&tc);
    while (tc--)
    {
        int a[100],j=1,count=0,res=0,zero=0,z;
        scanf("%lld",&n);
        i=log2(n);
 
        c=i;
        while(n>0)
        {
            m=n%2;
            n=n/2;
            a[i]=m;
            i--;
        }
//        for(i=0; i<c+1; i++) printf("%d",a[i]);
//        printf("\n");
//        printf("c %d\n",c);
        for(i=c; i>=0; i--)
        {
            if(a[i]==0)
            {
                zero++;
                continue;
            }
            while(a[i]==1 && j>0)
            {
                j=i;
                count++;
                i--;
            }
            break;
        }
//        printf("j %d\ncount %d\n",j,count);
        if(j==0&&count==1)
        {
            for(i=0; i<c+2; i++) res=pow(2,(c+1));
            printf("Case %d: %d\n", kase++,res);
            continue;
        }
        if(count==(c+1))
        {
            int b[c+3],base=1;
            b[0]=1;
            b[1]=0;
            for(i=2; i<c+2; i++) b[i]=1;
            for(i=c+1; i>=0; i--)
            {
                if(b[i]==1) res+=1*base;
                base*=2;
            }
            printf("Case %d: %d\n", kase++,res);
            continue;
        }
        if((zero+count)==c+1)
        {
            int b[c+3],base=1;
            b[0]=1;
            for(i=1; i<zero+2; i++) b[i]=0;
            for(z=0; z<count; z++,i++) b[i]=1;
            for(i=c+1; i>=0; i--)
            {
                if(b[i]==1) res+=1*base;
                base*=2;
            }
            printf("Case %d: %d\n", kase++,res);
            continue;
        }
        for(i=c; i>j-2; i--)
        {
////            printf("i %d\n",i);
            if(count-1)
            {
                a[i]=1;
                count--;
            }
            else a[i]=0;
            if(i==j-1)
            {
                a[i]=1;
            }
//            printf("%d %d\n",i,a[i]);
        }
//        for(i=0; i<=c; i++) printf("%d",a[i]);
//        printf("\n");
        int base=1;
        for(i=c; i>=0; i--)
        {
            if(a[i]==1) res+=1*base;
            base*=2;
        }
        printf("Case %d: %d\n",kase++,res);
 
 
//        printf("Case %d: %lld\n", c++,j);
    }
    return 0;
}
