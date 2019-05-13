#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<numeric>
#include<cmath>
#include<cstring>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define VSORT(v) sort(v.begin(), v.end());
#define VE vector<int>
#define VEP vector<pair<int,int>>
#define llong long long
#define pb(a) push_back(a)
using namespace std;
int dp[/*index*/][/*cost*/];
int lim;
int cost_vec[/*num*/];
int val_vec[/*num*/];
int fnd(int index,int cost);
int main(){
    memset(dp,-1,sizeof(dp));
    int cost;
    int ans = fnd(0,cost);
    cout<<ans<<endl;
    return 0;
}
int fnd(int index,int cost){
    if(dp[index][cost] >= 0){
        return dp[index][cost];
    }
    int res;
    if(index==lim){
        res=0;
    }else if(cost < cost_vec[index]){
        res = fnd(index+1,cost);
    }else{
        res = max(fnd(index+1,cost),fnd(index+1,cost-cost_vec[index])+val_vec[index]);
    }
    return dp[index][cost] = res;
}