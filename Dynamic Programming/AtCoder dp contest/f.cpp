#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    vector<vector<ll> >a(n+1, vector<ll>(m+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1] == t[j-1])
                a[i][j] = a[i-1][j-1]+1;
            else
                a[i][j] = max(a[i-1][j], a[i][j-1]);
        }
    }
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int x=n, y=m;
    string ans="";
    while(x!=0 && y!=0){
        if(a[x-1][y] == a[x][y])
            --x;
        else if(a[x][y-1] == a[x][y])
            --y;
        else{
            ans = t[y-1]+ans;
            --x;
            --y;
        }
    }
    cout << ans << endl;
    return 0;
}