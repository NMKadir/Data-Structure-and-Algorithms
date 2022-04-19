#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
const ll mod = 1e9+7;
const ll INF = 1e18L + 7;
const ll nax = 10123;
//ll dp[nax][2];
char k[nax];
void add_self(int& a, int b){
    a += b;
    if(a>=mod)
        a-=mod;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    scanf("%s",k);
    int d;
    scanf("%d",&d);
    int len = strlen(k);
    vector<vector<int> >dp(d, vector<int>(2));
    dp[0][0]=1;
    for(int i=0; i<len; i++){
        vector<vector<int> >new_dp(d, vector<int>(2));
        for(int sum=0; sum<d; sum++){
            for(bool sm_already : {false, true}){
                for(int digit=0; digit<10; digit++){
                    if(digit > k[i]-'0' and !sm_already){
                        break;
                    }
                    add_self(new_dp[(sum+digit) % d]
                    [sm_already || digit<k[i]-'0'],dp[sum][sm_already]);
                }
            }
        }
        dp=new_dp;
    }

    int ans = (dp[0][false]+dp[0][true])%mod;
    --ans;
    if(ans==-1)
        ans=mod-1;
    printf("%d\n",ans);
    return 0;
}