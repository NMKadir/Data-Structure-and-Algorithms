#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define MOD 10000007
int n;
int hap[100005][4];
int dp[100005][4];
int happy(int day, int flag){
    if(day==n)
        return 0;
    if(dp[day][flag] != -1)
        return dp[day][flag];
    int maxi=INT_MIN;
    if(flag==0){
        maxi = max(maxi, hap[day][1]+happy(day+1, 1));
        maxi = max(maxi, hap[day][2]+happy(day+1, 2));
        maxi = max(maxi, hap[day][3]+happy(day+1, 3));
    }
    else if(flag==1){
        maxi = max(maxi, hap[day][2]+happy(day+1, 2));
        maxi = max(maxi, hap[day][3]+happy(day+1, 3));
    }
    else if(flag==2){
        maxi = max(maxi, hap[day][1]+happy(day+1, 1));
        maxi = max(maxi, hap[day][3]+happy(day+1, 3));
    }
    else{
        maxi = max(maxi, hap[day][1]+happy(day+1, 1));
        maxi = max(maxi, hap[day][2]+happy(day+1, 2));
    }
    return dp[day][flag]=maxi;
}
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=1; j<=3; j++){
            cin>>hap[i][j];
        }
    }
    memset(dp,-1,sizeof dp);
    cout << happy(0,0);
    return 0;
}