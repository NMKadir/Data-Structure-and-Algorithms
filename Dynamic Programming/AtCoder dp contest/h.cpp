#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll h,w;
char a[10001][10001];
ll dp[10001][10001];
ll solve(ll i, ll j){
    if(a[i][j] == '#')
        return 0;
    if(i==h-1 && j==w-1)
        return 1;
    if(i>=h || j>=w)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j]%mod;
    return dp[i][j]=(solve(i, j+1)%mod + solve(i+1, j)%mod)%mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h >> w;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0,0) << endl;
    return 0;
}