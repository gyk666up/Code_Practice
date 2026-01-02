#include<bits/stdc++.h>
using namespace std;
int r;
const int N=1e3+1;
int a[N][N];
int dp[N][N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>r;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=i;j++)cin>>a[i][j];
    }
    for(int i=r;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {                  //下面是i+1
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
        }
    }
    cout<<dp[1][1];
    return 0;
}