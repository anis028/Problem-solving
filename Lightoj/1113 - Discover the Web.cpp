#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string a[105],s;
    int tc,p=1;
    scanf("%d",&tc);
    getchar();
    while(tc--)
    {
        printf("Case %d:\n",p++);
        a[0]="visit http://www.lightoj.com/";
        int i=0,high=-2;
        while(getline(cin,s))
        {
            if(s.compare("QUIT")==0)
                break;
            if(s[0]=='V')
            {
                i++;
                high=i;
                a[i]=s;
                for(int j=6; a[i][j];j++)printf("%c",a[i][j]);
                printf("\n");
            }
            if(s[0]=='B')
            {
                i--;
                if(i==-1){printf("Ignored\n");i++;}
                else{for(int j=6; a[i][j];j++)printf("%c",a[i][j]);
                printf("\n");}
            }
            if(s[0]=='F')
            {
                i++;
                if(i>high){printf("Ignored\n");i--;}
                else {for(int j=6; a[i][j];j++)printf("%c",a[i][j]);
                printf("\n");}
            }
        }
    }
 
    return 0;
}
