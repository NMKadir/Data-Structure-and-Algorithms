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
    ///implementation of floyd warshal algorithm
    //It's a dynamic programming algorithm
    //It's used to find shortest path between all pairs of nodes
    ll n; //number of nodes
    cin>>n;
    vector<vector<ll>> graph;
    for(ll i=0;i<n;i++){
        vector<ll> temp;
        for(ll j=0;j<n;j++){
            ll x;
            cin>>x;
            temp.push_back(x);
        }
        graph.push_back(temp);
    } ///input of graph

    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(graph[i][j]==-1){
                graph[i][j] = mod;
            }
        }
    } ///replacing -1 with mod

    for(ll k=0;k<n;k++){
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(graph[i][j]>graph[i][k]+graph[k][j] && graph[i][k]!=mod && graph[k][j]!=mod){
                    graph[i][j] = graph[i][k]+graph[k][j]; ///relaxing all edges
                }
            }
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(graph[i][j]==mod){
                cout<<"INF"<<" ";
            }
            else{
                cout<<graph[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}