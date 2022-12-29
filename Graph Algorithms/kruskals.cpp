#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define llu unsigned long long int
const ll INF = 1e9+7;
const ll INF1 = 1e18L + 7;
const ll nax = 1e5+2;
//Disjoint Set Union
ll parent[nax];
ll sz[nax];
ll make_set(ll x){
    parent[x]=x;
    sz[x]=1;
}
ll find(ll x){
    if(parent[x]==x) return x;
    ///return find(parent[x]);//without path compression
    return parent[x]=find(parent[x]);//path compression
}
void Union(ll x, ll y){
    x=find(x);
    y=find(y);
    if(x!=y){
        if(sz[x]<sz[y])//union by size
            swap(x,y);
        parent[y]=x;
        sz[x]+=sz[y];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ///implementation of MST (Kruskal's Algorithm)
    //It's a greedy algorithm
    ll N,m;
    cin>>N>>m;
    vector<vector<ll>> edges;
    for(ll i=0;i<m;i++){
        ll x,y,wt;
        cin>>x>>y>>wt;
        edges.push_back({wt,x,y});
    }//input of graph
    for(ll i=0;i<N;i++){
        make_set(i);
    } //making set
    sort(edges.begin(),edges.end());
    ll sum=0;
    for(auto it:edges){
        ll wt=it[0];//weight
        ll u=it[1];//node
        ll v=it[2];//node
        ll x = find(u);//parent of u
        ll y = find(v);//parent of v
        if(x==y) continue;//cycle
        else{
            cout<<u<<" "<<v<<endl;//printing edge
            sum+=wt;//adding weight
            Union(u,v);//union
        }//adding edge
    }
    cout<<sum<<endl;
    return 0;
}