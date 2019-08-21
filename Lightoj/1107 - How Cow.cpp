#include<stdio.h>
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--){
        int x1,x2,y1,y2,i,x,y,num;
        printf("Case %d:\n",p++);
        scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&num);
        for(i=0;i<num;i++){
            scanf("%d %d",&x,&y);
            if(x>=x1&&x<=x2&&y>=y1&&y<=y2)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

