#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   vvi           vector<vector<int> >
#define   vi            vector<int>
using namespace std;
typedef long long ll;
typedef double dbl;
 
int prime [555];
 
bool is_prime(int n){
    for(long long i=2; i*i<=n; ++i){
        if(n%i==0) return 0;
    }
    return 1;
}
 
long long d[555][555];
 
void init(){
    int n=0;
    for(int i=2; n!=500; ++i){
        if(is_prime(i)){
            prime[++n]=i;
        }
    }
    d[0][0]=1;
    for(int i=1; i<=500; ++i){
        for(int j=1; j<=i; ++j){
            d[i][j]+=d[i-1][j-1]*(prime[j]-1);
            if(i>j) d[i][j]+=d[i-1][j]*prime[j];
            d[i][j]%=1000000007;
        }
    }
}
 
int main () {
    init();
    int t,k,p;
    scanf("%d",&t);
    for(int cse=1; cse<=t; ++cse){
        scanf("%d %d",&k,&p);
        printf("Case %d: %lld\n",cse,d[k][p]);
    }
    return 0;
}
