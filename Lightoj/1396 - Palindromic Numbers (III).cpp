#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=100010;
char d[maxn],a[maxn];int cnt;
void put(int len)
{
    if(len==-1){
        putchar('1'); rep(i,1,cnt-1) putchar('0');
        putchar('1'); putchar('\n'); return ;
    }
    rep(i,1,len) putchar(a[i]); putchar('\n');
}
void cal()
{
    cnt=strlen(d+1);
    rep(i,1,cnt/2) swap(d[i],d[cnt+1-i]);
    rep(i,cnt/2+1,cnt) a[i]=d[i];
    rep(i,1,cnt/2) a[i]=a[cnt+1-i];
    for(int i=cnt;i>=1;i--)
      if(a[i]>d[i]){
         put(cnt); return ;
      }
    else if(a[i]<d[i]) break;
    rep(i,cnt/2+1,cnt){
        if(a[i]<'9') {
            a[i]++;
            rep(j,cnt-i+2,i-1) a[j]='0';
            a[cnt+1-i]=a[i];
            put(cnt); return ;
        }
    }
    put(-1); return ;
}
int main()
{
    int T,C=0,x;
    scanf("%d",&T);
    while(T--){
        scanf("%s",d+1);
        printf("Case %d: ",++C);
        cal();
    }
    return 0;
}
