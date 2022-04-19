#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
const ll mod = 1e9+7;
const ll INF = 1e18L + 7;
const ll nax = 10123;
ll dp[1002][1002];
ll solve(ll i, ll j, ll k){
    if(k>j || k>i)
        return 0;
    if(k==(ll)0)
        return 1;
    if(i==(ll)1)
        return j;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    ll ans = (j * solve(i-1, j-1, k-1)) + solve(i-1, j, k);
    return dp[i][j]=ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    scanf("%d",&t);
    int p=t;
    while(t--){
        ll n,k;
        scanf("%lld%lld", &n,&k);
        printf("Case %d: ", p-t);
        memset(dp, -1, sizeof dp);
        printf("%lld\n", solve(n,n,k));
    }
    return 0;
}