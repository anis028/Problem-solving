#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   vvi           vector<vector<int> >
#define   vi            vector<int>
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef double dbl;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc=1,cas=1;
    cin>>tc;
    while(tc--){
        double result, Tarea, r1, r2, r3, a, b, c, angleA, angleB, angleC, area1, area2, area3, s;
        cin>>r1>>r2>>r3;
        a = r1+r2;
        b = r1+r3;
        c = r2+r3;
        angleA = acos((b*b + c*c - a*a) / (2*b*c)) * 180.0/PI;
        angleB = acos((a*a + c*c - b*b) / (2*a*c)) * 180.0/PI;
        angleC = acos((b*b + a*a - c*c) / (2*b*a)) * 180.0/PI;
        area1 = 0.5 * (r1*r1) * (angleC * (PI/180.0));
        area2 = 0.5 * (r2*r2) * (angleB * (PI/180.0));
        area3 = 0.5 * (r3*r3) * (angleA * (PI/180.0));
        s = (a+b+c) / 2.0;
        Tarea = sqrt(s * (s-a) * (s-b) * (s-c));
        result = Tarea - (area1 + area2 + area3);
        cout<<fixed<<setprecision(12)<<"Case "<<cas++<<": "<<result<<endl;
    }
    return 0;
}
/*sample
 
*/
