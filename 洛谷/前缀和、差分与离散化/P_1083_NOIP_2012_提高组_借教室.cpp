// // //差分 也是t的.  
// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // const int N=1e6+11;
// // struct node
// // {
// //     int d,s,t;
// // }dat[N];//订单
// // int a[N];//每天可借到教室数量
// // int diff[N];
// // int sum[N];
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     int n,m;cin>>n>>m;
// //     for(int i=1;i<=n;i++)
// //     {
// //         cin>>a[i];
// //         diff[i]=a[i]-a[i-1];//主要这里对差分数组初始化
// //     }
// //     bool flg=1;
// //     int id=-1;
// //     for(int i=1;i<=m;i++)
// //     {
// //         cin>>dat[i].d>>dat[i].s>>dat[i].t;
// //         //从s到d都要减去d
// //         diff[dat[i].s]-=dat[i].d;
// //         diff[dat[i].t+1]+=dat[i].d;
// //         for(int j=1;j<=n;j++)
// //         {
// //             a[j]=a[j-1]+diff[j];
// //             if(a[j]<0)
// //             {
// //                 flg=0;
// //                 id=i;
// //                 break;
// //             }
// //         }
// //         // sum[0]=0;
// //         // for(int j=1;j<=n;j++)
// //         // {
// //         //     sum[j]=sum[j-1]+diff[j];
// //         //     if(sum[j]>a[j])
// //         //     {
// //         //         flg=0;
// //         //         id=i;
// //         //         //cout<<"?"<<id<<endl;
// //         //         break;
// //         //     }
            
// //         // }
// //          //注意这两个点break的使用位置
// //         //找到第一个不符合的
// //         if(!flg) break; //发现错误立即退出
// //     }
// //     if(flg)cout<<0<<endl;
// //     else cout<<-1<<endl<<id;

// //     return 0;
// // }

// // //t啦
// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // int n,m;

// // const int N=1e6+11;
// // struct node
// // {
// //     int d,s,t;
// // }dat[N];
// // int a[N];//每天可租借的教室数量
// // int diff[N];
// // int sum[N];
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>m;
// //     for(int i=1;i<=n;i++)cin>>a[i];
// //     bool flg=1;
// //     int id=-1;
// //     for(int i=1;i<=m;i++)
// //     {
// //         cin>>dat[i].d>>dat[i].s>>dat[i].t;
// //         diff[dat[i].s]+=dat[i].d;
// //         diff[dat[i].t+1]-=dat[i].d;
// //         for(int j=1;j<=n;j++)
// //         {
// //             sum[j]=sum[j-1]+diff[j];
// //             if(flg&&sum[j]>a[j])
// //             {
// //                 flg=0;
// //                 id=i;
// //                 break;
// //             }
           
// //         }
// //         if(flg==0)break;
// //     }
// //     if(flg)cout<<0<<endl;
// //     else cout<<-1<<endl<<id;
// //     return 0;
// // }


// //二分+差分
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+11;
// //注意数据的范围和这行代码的位置
// #define int long long
// int diff[N],d[N],s[N],t[N];
// int a[N];
// int sum[N];
// int n,m;

// bool check(int x)
// {
//     memset(diff,0,sizeof diff);
//     for(int i=1;i<=x;i++)
//     {
//         diff[s[i]]+=d[i];
//         diff[t[i]+1]-=d[i];
//     }
//     sum[0]=0;
//     for(int i=1;i<=n;i++)
//     {
//         sum[i]=sum[i-1]+diff[i];
//         if(sum[i]>a[i])
//         {
//             return 0;
//         }
//     }
//     return 1;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     for(int i=1;i<=m;i++)cin>>d[i]>>s[i]>>t[i];
//     int l=0,r=m+1;
//     while(l+1!=r)
//     {
//         int mid=(l+r)/2;
//         if(check(mid))l=mid;
//         else r=mid;
//     }
//     if(l==m)cout<<0<<endl;
//     else cout<<-1<<endl<<l+1;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+11;
int diff[N];
int a[N];
int n,m;
int sum[N];
int d[N],s[N],t[N];
bool check(int x)
{
    memset(diff,0,sizeof diff);//!!!!避免受到上一轮的影响
    for(int i=1;i<=x;i++)
    {
        diff[s[i]]+=d[i];
        diff[t[i]+1]-=d[i];
    }
    sum[0]=0;//!!!
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+diff[i];
        if(sum[i]>a[i])return false;
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];

    int l=0,r=m+1;
    for(int i=1;i<=m;i++)cin>>d[i]>>s[i]>>t[i];

    while(l+1!=r)
    {
        int mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    if(l==m)cout<<0<<endl;
    else cout<<-1<<endl<<l+1;
    return 0;
}