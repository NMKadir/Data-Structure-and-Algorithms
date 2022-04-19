#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
const ll INF = 1e18L + 7;
//d[i][j] is the min cost of combine(i,j)
ll dp[405][405];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    vector<ll>a(n);
    for(int i=0; i<n; i++){
        scanf("%lld", &a[i]);
    }
    auto sum = [&](int L, int R){
        ll s=0;
        for(int i=L; i<=R; i++)
            s+=a[i];
        return s;
    };
    for(int L=n-1; L>=0; --L){
        for(int R=L; R<n; R++){
            if(L==R)
                dp[L][R] = 0;
            else{
                dp[L][R] = INF;
                ll s = sum(L,R);
                for(int i=L; i<R; i++){
                    dp[L][R] = min(dp[L][R], dp[L][i] + dp[i+1][R] + s);
                }
            }
        }
    }
    printf("%lld\n", dp[0][n-1]);
    return 0;
}