#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
const ll mod = 1e9+7;
const ll INF = 1e18L + 7;
int n;
ll dp[23][(1ll<<23)];
vector<vector<int> >x(23,vector<int>(23));
ll solve(int men, ll women){
    ll ans=0;//store ans
    if(dp[men][women]!=-1)
        return dp[men][women];
    if(men==0){
        for(int i=0; i<n; i++){
            ll l = (1ll<<i); //left
            if(women & l){
                if(x[men][i]){// cheak the j-th women is left 
                    dp[men][women]=1;//compatible
                    return 1;
                }
                else{
                    dp[men][women]=0;//not compatible
                    return 0;
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        if(women & (1ll<<i)){
            if(x[men][i])
                ans+=solve(men-1, women-(1ll<<i));
        }
    }
    ans%=mod;
    dp[men][women]=ans;
    return dp[men][women];
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &x[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<(1ll<<n); j++){
            dp[i][j]=-1; // memoization
        }
    }
    printf("%lld\n", solve(n-1, (1<<n)-1)); // all men and women are 
                                         //available(for n men there are 2^n women combination)
    return 0;
}