#include<bits/stdc++.h>
using namespace std;
#define ll long long
int N;
int main(){
    cin >> N;
    cout << fixed;
    cout << setprecision(10);
    vector<double>p(N+1);
    vector<vector<double> >dp(N+1, vector<double>(N+1));
    for(int i=1; i<=N; i++){
        cin >> p[i];
    }
    dp[0][0]=1;
    for(int i=1; i<=N; i++){
        for(int j=0; j<=i; j++){
            dp[i][j] = dp[i-1][j] * (1-p[i]);
            if(j!=0)
                dp[i][j] += (dp[i-1][j-1] * p[i]);
        }
    }
    double ans=0.00;
    for(int i=N; i>(N/2); i--){
        ans+=dp[N][i];
    }
    cout << ans << endl;
    return 0;
}