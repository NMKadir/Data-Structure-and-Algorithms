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
    ///single source shortest path algorithm
    ///works for both directed and undirected graphs
    ///works for only positive edges
    ll n,m;
    cin>>n>>m;
    vector<ll>dist(n+1,mod); ///distance of all nodes from source
    vector<vector<pair<ll,ll>>>graph(n+1); ///adjacency list (u,v,w) u->v with distance w
    ll u,v,w;
    for(ll i=0; i<m; i++){
        cin>>u>>v>>w;
        graph[u].push_back({v,w});//directed graph
        graph[v].push_back({u,w});
    }
    ll source;
    cin>>source;
    dist[source] = 0;
    set<pair<ll,ll>>s; ///set of pairs (node,distance) sorted by distance acending order
    s.insert({source,0});//inserting source node
    while(!s.empty()){
        auto it = *(s.begin());///extracting node with minimum distance
        s.erase(it);///erasing that node from set
        for(auto i : graph[it.first]){//iterating over all neighbours of that node
            if(dist[i.first]>dist[it.first]+i.second){
                //distance(node(v))>distance(parent(u))+weight(parent->node(u,v))
                //updating distance of node
                s.erase({i.first,dist[i.first]});
                //inserting new distance
                dist[i.first] = dist[it.first]+i.second; //d(v)=d(u)+w(u,v)
                s.insert({i.first,dist[i.first]});
            }
        }
    }
    for(ll i=1; i<=n; i++){
        if(dist[i]==mod)
            cout<<"-1 ";
        else
            cout<<dist[i]<<" ";
    }
    return 0;
}