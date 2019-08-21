#include<stdio.h>
#include<math.h>
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--){
        int ax,ay,bx,by,cx,cy,dx,dy,area;
        scanf("%d %d %d %d %d %d",&ax,&ay,&bx,&by,&cx,&cy);
        dx=cx-bx+ax;
        dy=ay-by+cy;
        area=abs(ax*(by-cy)+bx*(cy-ay)+cx*(ay-by));
        printf("Case %d: %d %d %d\n",p++,dx,dy,area);
    }
    return 0;
}
