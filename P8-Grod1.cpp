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
    char ar[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>ar[i][j];
        }
    }
    ll dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    // just calculate the sum of total number of paths from above and left of every state 
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(ar[i-1][j-1] == '#')
            {
                dp[i][j] = 0;
                continue;
            }
            if(i==1 && j==1)
            {
                dp[i][j] = 1;
            }
            else
            {
                // if(i>0 && j>0)
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
            }
        }
    }
    // for(i=0;i<=n;i++)
    // {
    //     for(j=0;j<=m;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<dp[n][m];
}
