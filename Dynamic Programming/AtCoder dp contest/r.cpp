#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
const ll mod = 1e9+7;
const ll INF = 1e18L + 7;
const ll nax = 2e5+10;
// ll dp[nax][2];
int n;
void add_self(int&a, int b){
    a = (a+b)%mod;
}
int mul(int a, int b){
    return (ll) a*b%mod;
}
class mat{
public:
    vector<vector<int> >t;
    mat(){
        t.resize(n,vector<int>(n));
    }
    mat operator*(const mat& b){
        mat c;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    add_self(c.t[i][j], mul(t[i][k], b.t[k][j]));
                }
            }
        }
        return c;
    }
};
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll k;
    scanf("%d%lld", &n,&k);
    vector<vector<int> >a(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&a[i][j]);
        }
    }
    mat ans;
    for(int i=0; i<n; i++)
        ans.t[i][i]=1;
    mat temp;
    temp.t = a;
    while(k){
        if(k%2){
            ans=ans*temp;
        }
        temp=temp*temp;
        k/=2;
    }
    int total=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            add_self(total, ans.t[i][j]);
        }
    }
    printf("%d\n", total);
    // vector<int>dp(n,1);
    // dp[i] -> number of ways to get into i-th vertex
    // for(ll step=0; step<k; step++){
    //     vector<int>new_dp(n);
    //     for(int i=0; i<n; i++){
    //         for(int j=0; j<n; j++){
    //             if(a[i][j]){
    //                 // new_dp[j] = (new_dp[j]+dp[i])%mod;
    //                 add_self(new_dp[j], dp[i]);
    //             }
    //         }
    //     }
    //     dp=new_dp;
    // }
    // int ans=0;
    // for(int i=0; i<n; i++){
    //     // printf("%d\n", dp[i]);
    //     add_self(ans, dp[i]);
    // }
    // printf("%d\n", ans);
    return 0;
}