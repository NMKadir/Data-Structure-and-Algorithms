#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
const ll mod = 1e9+7;
const ll INF = 1e18L + 7;
const ll nax = 1e5+5;
vector<int>edges[nax];
ll dp[nax][2];
void bfs(int vertex, int parent){
    dp[vertex][0]=1;
    dp[vertex][1]=1;
    for(auto child : edges[vertex]){
        if(child==parent)
            continue;
        bfs(child, vertex);
        dp[vertex][0] = (dp[vertex][0] * (dp[child][1]+dp[child][0])) % mod;
        dp[vertex][1] = (dp[vertex][1] * dp[child][0]) % mod;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);
    for(int i=0; i<n-1; i++){
        int a,b;
        scanf("%d%d", &a,&b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    bfs(1,-1);
    printf("%d\n", (dp[1][0]+dp[1][1])%mod);
    return 0;
}