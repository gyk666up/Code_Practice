// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// long long ans1,ans2;//矩形个数，正方形个数
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             ans1+=i*j;
//             ans2+=min(i,j);
//         }
//     }
//     cout<<ans2<<" "<<ans1-ans2<<endl;
//     return 0;
// }


//2025/12/16 
//没写出来
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m;cin>>n>>m;

//     int ans1=0,ans2=0;
//     for(int i=1;i<=min(n,m);i++)
//     ans1+=n/i;
//     return 0;
// }

//如果你确定了矩形的右下角是 (i, j)，那么这个矩形的左上角可以是 $(1, 1)$ 到 $(i, j)$ 区域内的任意一个点。

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;cin>>n>>m;
    long long ans1=0,ans2=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans1+=min(i,j);
            ans2+=i*j;
        }
    }
    cout<<ans1<<" "<<ans2-ans1<<endl;
}