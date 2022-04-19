#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
const ll mod = 1e9+7;
const ll INF = 1e18L + 7;
const ll nax = 2e5+10;
//ll dp[nax][2];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);
    int base=1;
    while(base<=n){
        base*=2;
    }
    vector<ll>tree(2*base);
    vector<int>h(n);
    vector<int>a(n);
    for(int i=0; i<n; i++){
        scanf("%d", &h[i]);
    }
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    vector<ll>dp(n+1); // total max beauty encountered so far if last taken flower has height i
    for(int flower=0; flower<n; ++flower){

        ll best=0;
        ll x=base+h[flower];
        while(x>1){
            if(x%2==1){
                best=max(best, tree[x-1]);
            }
            x/=2;
        }
        dp[h[flower]]=best+a[flower];

        for(int i=base+h[flower]; i>=1; i/=2){
            tree[i]=max(tree[i], dp[h[flower]]);
        }
        // for(int i=0; i<h[flower]; i++){
        //     dp[h[flower]] = max(dp[h[flower]], dp[i]+a[flower]);
        // }

    }

    ll ans=0;
    for(int i=0; i<=n; i++)
        ans=max(ans,dp[i]);
    printf("%lld\n", ans);

    return 0;
}