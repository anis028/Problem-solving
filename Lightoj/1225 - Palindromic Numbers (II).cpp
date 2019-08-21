#include<stdio.h>
#include<string.h>
 
int main()
{
    int tc,p=1,l,i,j;
    scanf("%d",&tc);
    while(tc--)
    {
        char a[15],b[15];
        scanf("%s",&a);
        l=strlen(a);
        for(i=0,j=l-1; i<l/2; i++,j--)
        {
            if(a[i]==a[j])continue;
            else break;
        }
        if(i==l/2) printf("Case %d: Yes\n",p++);
        else printf("Case %d: No\n",p++);
 
    }
    return 0;
}
