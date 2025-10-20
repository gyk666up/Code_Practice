// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+11;
// int a[N];
// int n,m;
// //二分总出一些小问题 < <= > >= 还要到底是输出r 还是l
// int find(int x)
// {
//     int l=0,r=n;
//     while(l<r)
//     {
//         int mid=(l+r)/2;
//         if(a[mid]>=x)r=mid;
//         else l=mid+1;
//     }
//     if(a[l]==x)return l;
//     else return -1;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     // while(m--)
//     // {
//     //     int x;cin>>x;
//     //     //使用lower_bound的前提是要保证数组是单调不减的
//     //     int ans=lower_bound(a+1,a+1+n,x)-a;
//     //     if(x!=a[ans])printf("-1 ");
//     //     else printf("%d ",ans);
//     // }
//     while(m--)
//     {
//         int x;cin>>x;
//         int ans=find(x);
//         cout<<ans<<" ";
//     }
//      return 0;
// }

// //B站上的标准写法——以后就按照这个模板写
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+11;
// int a[N];
// bool check(int num,int x)
// {
//     if(num<x)return true;
//     else return false;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m;cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     while(m--){
//         int x;cin>>x;
//         int l=0,r=n+1;
//         while(l+1<r)
//        {
//             int mid=(l+r)/2;
//             if(check(a[mid],x))
//              {
//               l=mid;
//               }
//              else r=mid;
//         }
//         if(a[r]==x)cout<<r<<" ";
//         else cout<<"-1 ";
//     }
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e6+11;
int a[N];
bool check(int num,int x)
{
    if(num<x)return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    while(m--)
    {
        int x;cin>>x;
        int l=0,r=n+1;
        //找第一个>=x
        while(l+1!=r)
        {
            int mid=(l+r)/2;
            if(check(a[mid],x))
            l=mid;
            else r=mid;
        }
        if(a[r]==x)cout<<r<<" ";
        else cout<<"-1 ";
    }
    return 0;
}