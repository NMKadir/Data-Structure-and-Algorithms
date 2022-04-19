#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, W;
ll w[109], v[109];
ll dp[109][100009];
ll knaps(ll id, ll wt){
    if(id==n)
        return 0;
    if(dp[id][wt] != -1)
        return dp[id][wt];
    ll ans = knaps(id+1, wt);
    if(w[id]+wt<=W){
        ans = max(ans, knaps(id+1, wt+w[id])+v[id]);
    }
    return dp[id][wt] = ans;
}
int main(){
    cin>>n>>W;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++)
    {
        cin>>w[i]>>v[i];
    }
    cout << knaps(0,0) <<endl;
    return 0;
}