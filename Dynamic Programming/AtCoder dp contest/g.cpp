#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define k 1000005
int N,M;
vector<ll>mp[1100000];
ll dp[1100000];
ll solve(ll i){
    if(dp[i]!=-1)
        return dp[i];
    ll ans=0;
    for(int j=0; j<mp[i].size(); j++){
        ans = max(ans, solve(mp[i][j])+1);
    }
    return dp[i]=ans;
}
int main(){
    cin >> N >> M;
    memset(dp, -1, sizeof dp);
    // fill(dp.begin(), dp.end(), -1);
    for(int i=0; i<M; i++){
        ll x,y;
        cin >> x >> y;
        x--,y--;
        mp[x].push_back(y);
    }
    // for(int i=1; i<=N; i++){
    //     cout << endl << i << "-->";
    //     while(!mp[i].empty()){
    //         ll p = mp[i].front();
    //         mp[i].pop();
    //         cout << p << " ";
    //     }
    //     cout << endl;
    // }
    ll ans=0;
    for(int i=0; i<N; i++){
        ans = max(ans, solve(i));
    }
    cout << ans << endl;
    return 0;
}