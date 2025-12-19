#include<bits/stdc++.h>
using namespace std;
int a[5];
int homework[30];
int dp[100];
int  main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    for(int i=1;i<=4;i++)cin>>a[i];

    for(int i=1;i<=4;i++)
    {
        int sum=0;
        for(int j=1;j<=a[i];j++)
        {
            cin>>homework[i];
            sum+=homework[i];
        }
        for(int j=1;j<=a[i];j++)
        {
            for(int k=sum/2;k>=0;k--)
            {
                dp[k]=max(dp[k],dp[k-homework[j]]+homework[j]);
            }
        }
    }
    cout<<sum-dp[sum/2];
    return 0;
}