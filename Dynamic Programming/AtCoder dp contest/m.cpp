#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
int main(){
    int n,k;
    scanf("%d%d", &n,&k);
    vector<ll>a(n+1);
    for(int i=1; i<=n; i++){
        scanf("%lld", &a[i]);
    }
    ll dp[n+1][k+1];
    dp[0][0] = 1;
    for(int i=1; i<=k; i++)
        dp[0][i] = 0;
    for(int child=1; child<=n; child++){
        vector<ll>sum(k+1);
        sum[0] = dp[child-1][0];
        for(int i=1; i<=k; i++)
            sum[i] = (sum[i-1] + dp[child-1][i])%mod;
        for(int candy=0; candy<=k; candy++){
            if(candy<=a[child])
                dp[child][candy] = sum[candy];
            else{
                ll non_exixt=candy-a[child]-1;
                dp[child][candy] = (sum[candy] - sum[non_exixt] + mod) % mod;
            }
            
        }
        sum.clear();
    }
    printf("%lld\n", dp[n][k]);
    return 0;
}