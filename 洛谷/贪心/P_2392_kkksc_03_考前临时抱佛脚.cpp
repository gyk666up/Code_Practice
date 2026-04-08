

#include<bits/stdc++.h>
using namespace std;
const int N=1020;
int s[5];
int a[5][N];
int dp[N];
int ans;
int main()
{
    for(int i=1;i<=4;i++)cin>>s[i];

    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=s[i];j++)cin>>a[i][j];
    }
    for(int i=1;i<=4;i++)
    {
        memset(dp,0,sizeof dp);
        int sum=0;
        for(int j=1;j<=s[i];j++)
        {
            sum+=a[i][j];
        }

        //不超过sum/2的最大数
        for(int j=1;j<=s[i];j++)
        {
            for(int k=sum/2;k>=0;k--)
            {
                if(k>=a[i][j])
                dp[k]=max(dp[k],dp[k-a[i][j]]+a[i][j]);
            }
        }
        ans+=(sum-dp[sum/2]);
    }
    cout<<ans;
    return 0;
}