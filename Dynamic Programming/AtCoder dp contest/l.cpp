#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[3005][3005][2];
ll solve(vector<ll>& a, int i, int j, int flag){
    if(i>j)
        return 0;
    if(dp[i][j][flag] != -1)
        return dp[i][j][flag];
    if(flag==1){
        return dp[i][j][flag] = max(a[i] + solve(a, i+1, j, 0), a[j] + solve(a, i, j-1, 0));
    }
    else{
        return dp[i][j][flag] = min(solve(a, i+1, j, 1),solve(a, i, j-1, 1));
    }
}
int main(){
    int n;
    scanf("%d", &n);
    vector<ll>a(n);
    ll tot=0;
    for(int i=0; i<n; i++){
        scanf("%lld", &a[i]);
        tot+=a[i];
    }
    memset(dp, -1, sizeof dp);
    ll taro = solve(a, 0, n-1, 1);
    ll jiro = tot - taro;
    printf("%lld\n", taro-jiro);
    return 0;
}