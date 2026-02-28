// //dfs哎呦不错！
// #include<bits/stdc++.h>
// using namespace std;
// int s[5];
// int a[5][30];
// int ans=0;
// int res=0x3f3f3f3f;
// int l,r;
// void dfs(int x,int y)//x是当前的科目
// {
//     if(y>s[x])
//     {
//         res=min(res,max(l,r));
//         return ;
//     }
    
//     //对于这个科目 要么左脑要么右脑

//     l+=a[x][y];
//     dfs(x,y+1);
//     l-=a[x][y];

//     r+=a[x][y];
//     dfs(x,y+1);
//     r-=a[x][y];
//     return ;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     for(int i=1;i<=4;i++)cin>>s[i];
//     for(int i=1;i<=4;i++)
//     {
//         for(int j=1;j<=s[i];j++)cin>>a[i][j];
//     }
//     for(int i=1;i<=4;i++)
//     {
//         res=0x3f3f3f3f;//min(res,左右脑的最大值)
//         l=0,r=0;
//         dfs(i,1);
//         ans+=res;
//     }
//     cout<<ans;
//     return 0;
// }


// //大问题没有 小细节一堆
// #include<bits/stdc++.h>
// using namespace std;
// const int N=100;
// int s[5];
// int a[5][102];
// int dp[5][100];//第j个作业 不超过一半时间的最大值
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     for(int i=1;i<=4;i++)cin>>s[i];

//     for(int i=1;i<=4;i++)
//     {
//         for(int j=1;j<=s[i];j++)cin>>a[i][j];
//     }
//     int ans=0;
//     for(int i=1;i<=4;i++)
//     {
//         memset(dp,0,sizeof dp);//没有这行代码下一轮的循环会受到上一轮的影响
//         dp[0][0]=0;
//         int sum=0;
//         for(int j=1;j<=s[i];j++)
//         {
//             sum+=a[i][j];
//         }
//         for(int j=1;j<=s[i];j++)
//         {
//             for(int k=0;k<=sum/2;k++)
//             {
//                 if(k>=a[i][j])
//                 {
//                     //dp[j][k]第j门习题时间不超过sum/2的最大值
//                     dp[j][k]=max(dp[j-1][k],dp[j][k-a[i][j]]+a[i][j]);
//                 }
//                 else
//                 dp[j][k]=dp[j-1][k];
                
//             }
//         }
//         ans+=sum-dp[s[i]][sum/2];
//     }
//     cout<<ans;
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int s[5];
// int a[29][1000];
// int dp[21][1000];//前i个习题耗费时间为j
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     for(int i=1;i<=4;i++)cin>>s[i];

//     for(int i=1;i<=4;i++)
//     {
//         for(int j=1;j<=s[i];j++)
//         cin>>a[i][j];
//     }
//     int ans=0;
//     //感觉像4个0 1 背包 体积是sum/2 找背包最大可以装的容量
//     for(int i=1;i<=4;i++)
//     {
//         int sum=0;
//         memset(dp,0,sizeof dp);
//         for(int j=1;j<=s[i];j++)
//         {
//             sum+=a[i][j];
//         }
//         for(int j=1;j<=s[i];j++)
//         {
//             for(int k=0;k<=sum/2;k++)
//             {
//                 if(k<a[i][j])
//                 dp[j][k]=dp[j-1][k];
//                 else
//                 {
//                     dp[j][k]=max(dp[j-1][k],dp[j-1][k-a[i][j]]+a[i][j]);
//                 }
//             }
//         }
//         ans+=sum-dp[s[i]][sum/2];
//     }
//     cout<<ans;
    
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int s[5];
// const int N=1e4;
// int a[N][N];
// int dp[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     for(int i=1;i<=4;i++)cin>>s[i];
//     for(int i=1;i<=4;i++)
//     {
//         for(int j=1;j<=s[i];j++)cin>>a[i][j];
//     }

//     int ans=0;
//     for(int i=1;i<=4;i++)
//     {
//         int sum=0;
//         memset(dp,0,sizeof dp);//找最大值，初始化为0

//         for(int j=1;j<=s[i];j++)
//         {
//             sum+=a[i][j];
//         }
//         for(int j=1;j<=s[i];j++)
//         {
//             for(int k=sum/2;k>=a[i][j];k--)
//             {
//                 //注意这里是max，我们要找的是不超过sum/2的最大整数
//                 dp[k]=max(dp[k],dp[k-a[i][j]]+a[i][j]);
//             }
//         }
//         ans+=(sum-dp[sum/2]);
//     }
//     cout<<ans;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int s[5];
int a[21][100];
int dp[1002];
int ans=0;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    for(int i=1;i<=4;i++)cin>>s[i];
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=s[i];j++)cin>>a[i][j];
    }

    for(int i=1;i<=4;i++)
    {
        int sum=0;
        memset(dp,0,sizeof dp);
        for(int j=1;j<=s[i];j++)
        {
            sum+=a[i][j];
        }

        for(int j=1;j<=s[i];j++)
        {
            for(int k=sum/2;k>=0;k--)
            {
                if(k>=a[i][j])
                {
                    dp[k]=max(dp[k],dp[k-a[i][j]]+a[i][j]);
                }
            }
        }
        ans+=sum-dp[sum/2];
    }
    cout<<ans;
    return 0;
}