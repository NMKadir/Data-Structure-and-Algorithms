#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
const ll mod = 1e9+7;
const ll INF = 1e18L + 7;
const ll nax = 10123;
int n;
int arr[301][301];
int dp[301][301];
int solve(int i, int j){
    if(i>=(2*n)-1 || j>n)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans=0;
    ans = max(solve(i+1, j+1)+arr[i][j], solve(i+1, j)+arr[i][j]);
    return dp[i][j]=ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    scanf("%d",&t);
    int k=t;
    while(t--){
        // printf("\n");
        scanf("%d",&n);
        int len = (2*n)-1;
        memset(arr, 0, sizeof arr);
        memset(dp, -1, sizeof dp);
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                scanf("%d", &arr[i][j]);
            }
        }
        for(int i=n; i<len; i++){
            for(int j=i-n+1; j<n; j++){
                scanf("%d", &arr[i][j]);
            }
        }
        // for(int i=0; i<len; i++){
        //     for (int j = 0; j<len; j++){
        //         printf("%d ", arr[i][j]);
        //     }
        //     printf("\n");
        // }
        printf("Case %d: ", k-t);
        printf("%d\n", solve(0,0));
    }
    return 0;
}