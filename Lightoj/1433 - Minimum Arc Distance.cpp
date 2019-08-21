#include<stdio.h>
#include<math.h>
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--){
        double o_x,o_y,a_x,a_y,b_x,b_y,oa,ob,ab,theta;
        scanf("%lf %lf %lf %lf %lf %lf",&o_x,&o_y,&a_x,&a_y,&b_x,&b_y);
        oa=sqrt(pow((o_x-a_x),2)+pow((o_y-a_y),2));
        ob=sqrt(pow((o_x-b_x),2)+pow((o_y-b_y),2));
        ab=sqrt(pow((a_x-b_x),2)+pow((a_y-b_y),2));
        theta=acos(((oa*oa)+(ob*ob)-(ab*ab))/(2*oa*ob));
        printf("Case %d: %lf\n",p++,oa*theta);
    }
    return 0;
}
