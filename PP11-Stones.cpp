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
    ll ar[mx];
    for(i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    ll dp[mx] = {2};
    for(i=0;i<=m;i++)
    dp[i] = 2;
    // memset(dp,2,sizeof(dp));
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if((ar[j]<=i) && (dp[i-ar[j]] == 2))
            {
                dp[i] = 1;
            }
        }
    }
    // for(i=0;i<=m;i++)
    // cout<<dp[i]<<" ";
    // cout<<"\n";
    if(dp[m]==1)
    cout<<"First\n";
    else
    cout<<"Second\n";
}
