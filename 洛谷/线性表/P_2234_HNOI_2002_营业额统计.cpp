//二分查找的前提是有序数组 这里是无序的 不可以用
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// const int N=1e6+11;
// int a[N];
// // 2 2 3 3 4
// // 2 3 4 5 6
// int binary_search1(int l,int r,int x)
// {
//     while(l+1!=r)
//     {
//         int mid=(l+r)/2;
//         if(a[mid]<=x)l=mid;
//         else r=mid;
//     }
//     return a[l];
// }
// int binary_search2(int l,int  r,int x)
// {
//     while(l+1!=r)
//     {
//         int mid=(l+r)/2;
//         if(a[mid]<=x)l=mid;
//         else r=mid;
//     }
//     return a[r];
// }
// int ans=0x3f3f3;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     int sum=a[1];
//     for(int i=2;i<=n;i++)
//     {
//         //有点像二分 找最后一个<=x 和第一个>=x;
//         int x;cin>>x;
//         int x1=binary_search1(0,i,x);
//         int x2=binary_search2(0,i,x);
//         ans+=min(abs(x-x1),abs(x-x2));
//     }
//     cout<<ans<<endl;
//     return 0;
// }



//题解的方法好难！！！
//这个是自己的思路 侥幸通过
#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans=0;
const int N=1e6+11;
int a[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    //先暴力枚举看一下  没想到可以通过
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=2;i<=n;i++)
    {
        int sum1=abs(a[i]-a[1]);
        //j是i前面的某一天 一个一个判断看哪个最小
        for(int j=1;j<=i-1;j++)
        {
            sum1=min(sum1,abs(a[j]-a[i]));
        }
        ans+=sum1;
    }
    cout<<ans+a[1];//第一天的最小波动值就是a[1]
    return 0;
}






















