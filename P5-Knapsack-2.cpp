#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define pb push_back
// #define mp make_pair
#define nt _int128 
#define fir first
#define sec second
#define fast_as_levi ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define debug cout<<"debugged\n";
#define inf 0x3f3f3f3f
 
const ll mod = 1e9 + 7;
const ll mx = 2e6 + 5;
const ll mxi = 2e3 + 5;

int main()
{
    fast_as_levi;
    ll i,j,n,m;
    cin>>n>>m;
    //using specifically optimized knapsack here,
    //as standard O(n*m) knapsack solution will timeout due to the heavy constraints given in the problem
    ll wt[n],cs[n];
    ll value_sum = 0;
    
    for(i=0;i<n;i++)
    {
        cin>>wt[i]>>cs[i];
        value_sum += cs[i]; 
    }
    //So, here, instead of iterating over the accumulated weights(which we do conventionally in 0-1 knapsack),
    //we will iterate over accumulated values here instead
    vector<ll> dp(value_sum+1,inf);
    dp[0] = 0;
    for(i=0;i<n;i++)
    {
        for(j = value_sum - cs[i];j>=0;j--)
        {
            dp[j+cs[i]] = min(dp[j+cs[i]] , dp[j] + wt[i]);
        }
    }
    ll ans = 0;
    for(i=0;i<=value_sum;i++)
    {
        if(dp[i]<=m)
        {
            ans = max(ans,i);
        }
    }
    cout<<ans;
}
