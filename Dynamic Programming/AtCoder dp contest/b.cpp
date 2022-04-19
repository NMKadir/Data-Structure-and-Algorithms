#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n, k;
    cin >> n >> k;
    int h[n];
    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    vector<ll>dp(n,LLONG_MAX);
    dp[0]=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<=i+k; j++){
            if(j<n)
                dp[j] = min(dp[j], dp[i]+abs(h[i]-h[j]));
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}