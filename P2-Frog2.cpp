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
    ll i,n,k;
    cin>>n>>k;
    ll ar[n];
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    ll dp[n+1]={0};
    dp[1] = abs(ar[1]-ar[0]);
    for(i=2;i<n;i++)
    {
        ll mi = INT_MAX; 
        for(ll j=1;j<=k;j++)
        {
            if(i>=j)
            mi = min(mi,dp[i-j] + abs(ar[i]-ar[i-j]));
        }
        dp[i] = mi;
    }
    cout<<dp[n-1];
}
