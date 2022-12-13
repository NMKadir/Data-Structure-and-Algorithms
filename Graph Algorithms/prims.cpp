#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define llu unsigned long long int
const ll INF = 1e9+7;
const ll INF1 = 1e18L + 7;
const ll nax = 1e5+2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ///implementation of MST
    //It's a greedy algorithm
    ll N,m;
    cin>>N>>m;
    vector<pair<ll,ll>> graph[N+1];
    for(ll i=0;i<m;i++){
        ll x,y,wt;
        cin>>x>>y>>wt;
        graph[x].push_back({y,wt});
        graph[y].push_back({x,wt}); ///undirected graph
    }//input of graph
    vector<ll>parent(N,-1);
    vector<ll>key(N,INF);
    vector<bool>inMST(N,false);
    key[0] = 0;

    //////////////O(n^2)//////////////
    /*
    for(int count=0; count<N-1; count++){
        ll mini = INT_MAX, u;
        for(ll i=0;i<N;i++){
            if(inMST[i]==false && key[i]<mini){
                mini = key[i];
                u = i;
            }
        } ///finding minimum key
        ///adding u to MST
        inMST[u] = true;
        for(auto it:graph[u]){
            ll v = it.first;//node
            ll weight = it.second;//weight
            if(inMST[v]==false && weight<key[v]){
                parent[v] = u; //updating parent
                key[v] = weight;//updating key
            }
        } ///relaxing all edges
    }
    ///printing MST
    ll sum=0;
    for(ll i=1;i<N;i++){
        sum+=key[i];
    }
    for(ll i=1;i<N;i++){
        cout<<parent[i]<<" "<<i<<endl;
    }
    cout<<"Total cost of mst O(n^2): "<<sum<<endl;
    */

    ///////////O(nlogn)///////////////

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    //min heap
    //first element is key
    //second element is node
    pq.push({0,0});//pushing 0th node
    while(!pq.empty()){
        ll u = pq.top().second;//node
        pq.pop();//removing node
        inMST[u] = true;//adding u to MST
        for(auto it:graph[u]){//relaxing all edges
            ll v = it.first;//node
            ll weight = it.second;//weight
            if(inMST[v]==false && weight<key[v]){//relaxing
                parent[v] = u;//updating parent
                key[v] = weight;//updating key
                pq.push({key[v],v});//pushing node
            }//relaxing all edges
        }
    }
    ///printing MST
    ll sum=0;
    for(ll i=1;i<N;i++){
        sum+=key[i];
    }
    for(ll i=1;i<N;i++){
        cout<<parent[i]<<" "<<i<<endl;
    }
    cout<<"Total cost of mst (O(nlogn)): "<<sum<<endl;

    return 0;
}