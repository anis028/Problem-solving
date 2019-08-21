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
 
int max_rec_area_in_histogram(int hist[], int n)
{
    stack<int> st;
    int maxArea = 0;
 
    for(int i = 0; i < n; ++i) {
        if(st.empty() || hist[st.top()] <= hist[i])
            st.push(i);
        else {
            while(!st.empty() && hist[st.top()] > hist[i]) {
                int t = st.top();
                st.pop();
 
                maxArea = max(maxArea, hist[t] * ((st.empty())? i : i - st.top() - 1));
            }
 
            st.push(i);
        }
    }
 
    while(!st.empty()) {
        int t = st.top();
        st.pop();
 
        maxArea = max(maxArea, hist[t] * ((st.empty())? n : n - st.top() - 1));
    }
 
    return maxArea;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc=1,cas=1;
    cin>>tc;
    while(tc--){
        int r,c;
        cin>>r>>c;
        string s;
        int ara[c+2],ans=0;
        mm(ara,0);
        for(int i=0;i<r;i++){
            cin>>s;
            for(int j=0;j<c;j++)
                if(s[j]=='1') ara[j]=0;
                else ara[j]++;
            ans=max(ans,max_rec_area_in_histogram(ara,c));
        }
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
/*sample
 
*/
 

