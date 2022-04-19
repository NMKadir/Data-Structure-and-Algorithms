#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, W;
ll w[109], v[109];
ll dp[109][100009];
ll knaps(ll id, ll val){
    if(id>n)
        return 1e15;
    if(val==0)
        return 0;
    if(dp[id][val]!=-1)
        return dp[id][val];
    //Dont
    ll ans = knaps(id+1, val);
    //choose
    if(val-v[id]>=0){
        ans = min(ans, knaps(id+1, val-v[id])+w[id]);
    }
    return dp[id][val]=ans;
}
int main(){
    cin>>n>>W;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++)
    {
        cin>>w[i]>>v[i];
    }
    ll ans = 1e5;
    for(ll i=ans; i>=0; i--){
        if(knaps(0,i)<=W){
            cout << i << endl;
            break;
        }
    }
   // cout << knaps(0,0) <<endl;
    return 0;
}