#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,k;
    scanf("%d%d", &n, &k);
    vector<int>a(n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    vector<bool>dp(k+1);
    for(int i=0; i<=k; ++i){
        for(int j=0; j<n; ++j){
            if(i>=a[j] and !dp[i-a[j]])
                dp[i] = true;
        }
    }
    puts(dp[k] ? "First" : "Second");
    return 0;
}