// //错误百出
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2004;
// int c[N][N];//记录C（i,j)%k的结果
// int t,k;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>t>>k;
//     for(int i=0;i<=2002;i++)
//     {
//         for(int j=0;j<=2002;j++)
//         {
//             if(i==0)c[i][j]=1;
//             else if(j==0) c[i][j]=c[i-1][j]%k;
//             else c[i][j]=(c[i-1][j-1]+c[i-1][j])%k;
//         }
//     }
    
//     while(t--)
//     {
//         int ans=0;
//         int n,m;cin>>n>>m;
//         for(int i=0;i<=n;i++)
//         {
//             for(int j=0;j<=min(i,m);j++)
//             {
//                 if(c[i][j]==0)ans++;
//             }
//         }
//         cout<<ans<<endl;
//     }
//     return 0;
// }


// //这样仍会有一个点t的
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 2001;
// int c[N][N];
// int t, k;

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> t >> k;

//     for(int i = 0; i <= 2000; i++)
//     {
//         for(int j = 0; j <= i; j++)
//         {
//             if(j == 0 || j == i)
//                 c[i][j] = 1 % k;
//             else
//                 c[i][j] = (c[i-1][j-1] + c[i-1][j]) % k;
//         }
//     }

//     while(t--)
//     {
//         int n, m;
//         cin >> n >> m;
//         int ans = 0;

//         for(int i = 0; i <= n; i++)
//         {
//             for(int j = 0; j <= min(i, m); j++)
//             {
//                 if(c[i][j] == 0) ans++;
//             }
//         }
//         cout << ans << '\n';
//     }
//     return 0;
// }


// 
// //这样仍会有一个点t的-》//使用二维前缀来优化
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 2001;
// int c[N][N];
// int b[N][N];
// int t, k;
// int prefix[N][N];
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> t >> k;

//     for(int i = 0; i <= 2000; i++)
//     {
//         for(int j = 0; j <= i; j++)
//         {
//             if(j == 0 || j == i)
//                 c[i][j] = 1 % k;
//             else
//                 c[i][j] = (c[i-1][j-1] + c[i-1][j]) % k;
//         }
//     }
//     //构建bad数组 如果c[i][j]=0 b[i][j]=1;
//     // 不是组合数只能在 j ≤ i 有意义，而是：
//     // 二维前缀和必须是一个“完整矩形”，否则就不好查了。
//     for(int i=0;i<=2000;i++)
//     {
//         for(int j=0;j<=2000;j++)//这里也枚举到2000
//         {
//             if(j<=i&&c[i][j]==0)b[i][j]=1;
//             else b[i][j]=0;
//         }
//     }

//     //二维前缀和
//     for(int i=0;i<=2000;i++)
//     {
//         for(int j=0;j<=2000;j++)
//         {
//             //这种写法还是第一次见
//             prefix[i][j]=b[i][j];
//             if(i)prefix[i][j]+=prefix[i-1][j];
//             if(j)prefix[i][j]+=prefix[i][j-1];
//             if(i&&j)prefix[i][j]-=prefix[i-1][j-1];
//         }
//     }
//     while(t--)
//     {
//         int n,m;cin>>n>>m;
//         //虽然不影响正确性  如果不限制的话，你其实在查一个 “空白区域 + 有效区域”
//         m=min(n,m);//这里很关键，对于组合数来说，m 大于 n 的那一部分，完全没有任何意义
//         cout<<prefix[n][m]<<endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int c[N][N];
int b[N][N];
int prefix[N][N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,k;cin>>t>>k;
    for(int i=0;i<=2000;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0||j==i)
            {
                c[i][j]=1%k;
                if(c[i][j]==0)b[i][j]=1;
            }
            else
            {
                c[i][j]=(c[i-1][j]+c[i-1][j-1])%k;
                if(c[i][j]==0)b[i][j]=1;
            }
        }
    }
    for(int i=0;i<=2000;i++)
    {
        for(int j=0;j<=2000;j++)
        {
            prefix[i][j]=b[i][j];
            if(i)prefix[i][j]+=prefix[i-1][j];
            if(j)prefix[i][j]+=prefix[i][j-1];
            if(i&&j)prefix[i][j]-=prefix[i-1][j-1];
        }
    }
    
    while(t--){
    int n,m;cin>>n>>m;
    //m=min(n,m);
    cout<<prefix[n][m]<<endl;;

}
    return 0;
}