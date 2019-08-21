#include<stdio.h>
 
int main() {
    double p;
    int cases, caseNo = 0, n, m, k;
    for (scanf("%d", &cases); cases--; ) {
        scanf(" %d %d %d %lf ", &n, &m, &k, &p);
        printf("Case %d: %.10lf\n", ++caseNo, p * n * k);
    }
    return 0;
}
