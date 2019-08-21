#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   loop(i,x,n)   for(int i=x;i<n;i++)
#define   pb            push_back
#define   pii           pair<int,int>
#define   imax          2147483647
#define   pcase(x)      printf("Case %d: ",x)
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   pf1(x)        printf("%d\n",x)
#define   pf2(x,y)      printf("%d %d\n",x,y)
#define   sf1(x)        scanf("%d",&x)
#define   sf2(x,y)      scanf("%d %d",&x,&y)
 
using namespace std;
 
int main()
{
    int tc,p=1;
    int a[105][105];
    for(int i=0;i<105;i++)
        for(int j=0;j<100;j++) a[i][j]=0;
 
    for(int i=1;i<105;i++)
    {
        int number=i;
        //cout<<number<<endl;
        while(number%2==0)
        {
            number/=2;
            a[i][2]++;
        }
        while(number%3==0)
        {
            number/=3;
            a[i][3]++;
        }
        while(number%5==0)
        {
            number/=5;
            a[i][5]++;
        }
        while(number%7==0)
        {
            number/=7;
            a[i][7]++;
        }
        if(number>1) a[i][number]++;
    }
 
    for(int i=1;i<105;i++)
        for(int j=0;j<100;j++) a[i][j]+=a[i-1][j];
 
    scanf("%d",&tc);
    while(tc--)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %d = 2 (%d)",p++,n,a[n][2]);
        for(int i=3;i<100;i++)
            if(a[n][i]!=0) printf(" * %d (%d)",i,a[n][i]);
        printf("\n");
    }
    return 0;
}
/*sample
 
*/
