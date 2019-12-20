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
    ll i,n;
    cin>>n;
    ll ar[n],br[n],cr[n];
    for(i=0;i<n;i++)
    {
        cin>>ar[i]>>br[i]>>cr[i];
    }
    ll dp[n+1][3];
    for(i=0;i<=n;i++)
    {
        for(ll j=0;j<3;j++)
        dp[i][j]=0;
    }
    for(i=1;i<=n;i++)
    {
        dp[i][0] = ar[i-1] + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = br[i-1] + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = cr[i-1] + max(dp[i-1][0],dp[i-1][1]);
    }
    // for(i=0;i<=n;i++)
    // {
    //     for(ll j=0;j<n;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]));
}
