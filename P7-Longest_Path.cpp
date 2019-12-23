//Following the naive approach would lead to timeout as we have to perform dfs on all the nodes... 
// resulting in O(n^2)

//better to use the build dp solution based on calculating the respective lengths of the child nodes 

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

vector<ll> g[mx];
ll vis[mx];
ll dp[mx];
void dfs(ll s)
{
    vis[s] = 1;
    for(ll x : g[s])
    {
        if(!vis[x])
        {
            dfs(x);
        }
        dp[s] = max(dp[s], dp[x] + 1);
    }
    // return dp[s];
}

int main()
{
    fast_as_levi;
    ll i,j,n,e;
    cin>>n>>e;
    for(i=0;i<e;i++)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
    }
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    ll ans = 0;
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    // for(i=0;i<=n;i++)
    // {
    //     cout<<dp[i]<<" ";
    // }
    // cout<<"\n";
    for(i=1;i<=n;i++)
    {
        ans = max(dp[i],ans);
    }
    cout<<ans;                    
}
