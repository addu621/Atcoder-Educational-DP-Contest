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
    string s1,s2;
    cin>>s1>>s2;
    ll i,j;
    ll n = s1.length();
    ll m = s2.length();
    ll dp[n+1][m+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j] = 0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1; 
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string ans = "";
    i=n,j=m;
    while(i>0 && j>0)
    {
        if(s1[i-1] == s2[j-1])
        {
            ans += s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}
