#include<stdio.h>
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--){
        int a,b;
        scanf("%d %d",&a,&b);
        if (a%3==0)a=((a/3)*2)-1;
        else a=(a/3)*2;
        if(b%3==2)b=((b/3)*2)+1;
        else b=(b/3)*2;
        printf("Case %d: %d\n",p++,b-a);
    }
    return 0;
}
