#include <stdio.h>
 
long long Ax, Ay, Bx, By, dx, dy;
long long ABS (long long n)
{
    return n> 0? n:-n;
}
 
long Gcd(long long a,long long b)
{
    if(b==0)
        return a;
    else
        return Gcd(b, a%b);
}
 
int main()
{
    int i, T;
    scanf ("%d",&T);
    for (i = 1; i <= T; i++)
    {
        scanf ("%lld %lld %lld %lld",&Ax,&Ay,&Bx,&By);
        printf ("Case %d: %lld\n", i, Gcd(ABS(Ax-Bx),ABS(Ay-By))+1);
    }
    return 0;
}
