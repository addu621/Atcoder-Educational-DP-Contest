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
    ll i,j,n;
    cin>>n;
    ld dp[n+1][n+1];
    ld ar[n+1];
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j>0)
            {
                dp[i][j] += dp[i-1][j-1] * ar[i-1];     //for heads showing up 
            }
            dp[i][j] += dp[i-1][j] * (1-ar[i-1]);       //for tails showing up
        }
    }
    // for(i=0;i<=n;i++)
    // {
    //     for(j=0;j<=n;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    
    //The answer would be the sum of all cases, where number of heads are greater than tails,
    // i.e, we get heads more than in more than half of the cases when any set of coins are tossed 
    // or , where i > N/2.

    ld ans = 0;
    for(i=0;i<=n;i++)
    {
        if(i>n/2)
        ans += dp[n][i];
    }
    cout<<setprecision(12)<<ans;
}
