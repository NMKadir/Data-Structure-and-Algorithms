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
    vector<ll>adj[nax]; // Making a vector to store the adjacency list
    vector<bool>vis; // To check if the node is visited or not
    /// Taking the input
    //Taking how many nodes and edges are there
    ll n,m;
    cout<<"Enter the number of nodes and edges: \n";
    cin>>n>>m;
    //Taking the edges
    ll x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //Making the visited array of size nax+1 and initializing it with false
    vis.resize(nax+1,false);
    ///making a queue to store the nodes 
    queue<ll>q;
    //Taking the source node
    ll src;
    cout<<"Enter the source node: \n";
    cin>>src;
    //Pushing the source node in the queue
    q.push(src);
    //Marking the source node as visited
    vis[src] = true;
    while(!q.empty()){/// untill all nodes are visited
        ll node = q.front(); //Taking the front node
        q.pop(); //Popping the front node
        cout<<node<<" "; //Printing the node
        for(auto it:adj[node]){ //Traversing the adjacency list of the node
            if(!vis[it]){ //If the node is not visited
                q.push(it); //Pushing the node in the queue
                vis[it] = true; //Marking the node as visited
            }
        }
    }
    return 0;
}