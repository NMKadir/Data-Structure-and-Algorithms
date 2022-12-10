#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define llu unsigned long long int
const ll mod = 1e9+7;
const ll INF = 1e18L + 7;
const ll nax = 1e5+2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ///implementation of bellman ford algorithm
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> edges; //vector of edges where each edge is a vector of 3 elements
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    } //input of edges
    ll src;
    cin>>src;
    vector<ll> dist(n,mod); //distance of all nodes from source
    dist[src] = 0;
    for(ll i=0;i<n-1;i++){ //relaxing all edges n-1 times
        for(auto j : edges){
            ll u = j[0];
            ll v = j[1];
            ll w = j[2];
            if(dist[u]!=mod && dist[v]>dist[u]+w){
                dist[v] = dist[u]+w;
            }
        }
    }
    //checking for negative cycle
    for(auto j : edges){
        if(dist[j[0]]!=mod && dist[j[1]]>dist[j[0]]+j[2]){
            cout<<"Negative cycle detected";
            return 0;
        }
    }
    for(auto i : dist){
            cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}