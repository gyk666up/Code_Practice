// //怎么拆分成子问题啊，没思路诶
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+11;
// int a[N];
// int n;
// //暴力+前缀和尝试一下 tl
// int prefix[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         prefix[i]=prefix[i-1]+a[i];
//     }

//     int len=-1;
//     int ans=-0x3f3f3f3f;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=i;j<=n;j++)
//         {
//             //i---j
//             int temp=prefix[j]-prefix[i-1];
//             if(temp>ans)
//             {
//                 ans=temp;
//                 len=j-i+1;
//             }
//         }
//     }
//     cout<<ans;
//     return 0;
// }


// //“如果前面的和是负的，那就拖后腿，直接不要。”
// //dp[i] = 以 i 结尾的连续子段的最大和
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+11;
// int dp[N];
// int n;
// int a[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     dp[1]=a[1];
//     int ans=dp[1];
//     for(int i=2;i<=n;i++)
//     {
//         dp[i]=max(a[i],dp[i-1]+a[i]);
//         ans=max(ans,dp[i]);
//     }
//     cout<<ans;
//     return 0;
// }

