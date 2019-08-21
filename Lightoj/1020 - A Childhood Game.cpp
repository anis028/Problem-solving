#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    getchar();
    while(tc--)
    {
       int n;
       char s[9];
       scanf("%d %s",&n,&s);
       printf("Case %d: ",cas++);
       if(s[0]=='A')
       {
            if(n%3==1) printf("Bob\n");
            else printf("Alice\n");
       }
       else
       {
            if(n%3==0) printf("Alice\n");
            else printf("Bob\n");
       }
    }
    return 0;
}
