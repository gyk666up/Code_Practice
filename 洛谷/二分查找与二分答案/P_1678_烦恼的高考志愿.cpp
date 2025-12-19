// //这样其实是写麻烦了 最后一个<=x和第一个>=x的一定是相邻的
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// #define int long long
// int a[N];
// int m,n;
// //找最后一个<=x
// bool check1(int num,int x)
// {
//     if(num<=x)return 1;
//     else return 0;
// }
// bool check2(int num,int x)
// {
//     if(num<x)return 1;
//     else return 0;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>m>>n;
//     for(int i=1;i<=m;i++)cin>>a[i];

//     //因为这两个位置和x最接近
//     //我的思路：找最后一个<=x 找第一个>=x 取最小值
//     //二分查找的前提
//     sort(a+1,a+1+m);
//     int ans=0;
 
//     while(n--)
//     {
//         int x;cin>>x;
//         int l=0,r=m+1;
//         while(l+1!=r)
//         {
//             int mid=(l+r)/2;
//             if(check1(a[mid],x))l=mid;
//             else r=mid;
//         }
//         int temp1=abs(a[l]-x);

//         l=0,r=m+1;
//         while(l+1!=r)
//         {
//             int mid=(l+r)/2;
//             if(check2(a[mid],x))l=mid;
//             else r=mid;
//         }
//         int temp2=abs(a[r]-x);
//         //注意这里需要特判一下
//         if(x<a[1])ans+=a[1]-x;
//         else
//          ans+=min(temp1,temp2);
//     }
//     cout<<ans;
// }


// //注意特判的情况！~@@
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// #define int long long
// int a[N];
// int m,n;
// //找最后一个<=x
// bool check1(int num,int x)
// {
//     if(num<=x)return 1;
//     else return 0;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>m>>n;
//     for(int i=1;i<=m;i++)cin>>a[i];

//     //因为这两个位置和x最接近
//     //我的思路：找最后一个<=x 找第一个>=x 取最小值
//     //二分查找的前提
//     sort(a+1,a+1+m);
//     int ans=0;
 
//     while(n--)
//     {
//         int x;cin>>x;
//         int l=0,r=m+1;
//         while(l+1!=r)
//         {
//             int mid=(l+r)/2;
//             if(check1(a[mid],x))l=mid;
//             else r=mid;
//         }
//         int temp1=abs(a[l]-x);
//         int temp2=abs(a[l+1]-x);
//         //注意这里需要特判一下
//         if(x<a[1])ans+=a[1]-x;
//         else
//          ans+=min(temp1,temp2);
//     }
//     cout<<ans;
//     return 0;
// }



<<<<<<< HEAD
// //这道题掌握的不是很好 12//18
// //使用二分算法之前一定要先排序
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int m,n;
// const int N=1e5+11;
// int sc[N];
// int ans=0;
// bool check(int x,int target)
// {
//     if(x<=target)return true;
//     return false;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>m>>n;
//     for(int i=1;i<=m;i++)cin>>sc[i];
//     sort(sc+1,sc+1+m);
//     while(n--)
//     {
//         int x;cin>>x;
//         int l=0,r=m+1;
//         while(l+1!=r)
//         {
//             int mid=(l+r)/2;
//             if(check(sc[mid],x))l=mid;
//             else r=mid;
//         }
//         int temp1=abs(sc[l]-x);
//         int temp2=abs(sc[l+1]-x);
//         if(x<sc[1])ans+=sc[1]-x;
//         else ans+=min(temp1,temp2);
//     }
//     cout<<ans;
//     return 0;
// }


=======
//这道题掌握的不是很好 12//18
//使用二分算法之前一定要先排序
>>>>>>> 910700d7e6c08f10eaba22dc51f3fd35dfed6e15
#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,n;
const int N=1e5+11;
<<<<<<< HEAD
int a[N];
=======
int sc[N];
int ans=0;
>>>>>>> 910700d7e6c08f10eaba22dc51f3fd35dfed6e15
bool check(int x,int target)
{
    if(x<=target)return true;
    return false;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>m>>n;
<<<<<<< HEAD
    for(int i=1;i<=m;i++)cin>>a[i];
    sort(a+1,a+1+m);
    int ans=0;
    for(int i=1;i<=n;i++)
=======
    for(int i=1;i<=m;i++)cin>>sc[i];
    sort(sc+1,sc+1+m);
    while(n--)
>>>>>>> 910700d7e6c08f10eaba22dc51f3fd35dfed6e15
    {
        int x;cin>>x;
        int l=0,r=m+1;
        while(l+1!=r)
        {
            int mid=(l+r)/2;
<<<<<<< HEAD
            if(check(a[mid],x))l=mid;
            else r=mid;
        }
        int temp1=abs(a[l]-x);
        int temp2=abs(a[l+1]-x);

        //主要是区间包括a[0]这个不合法的元素
        if(x<a[1])ans+=a[1]-x;
        else ans+=min(temp1,temp2);
        ans+=min(temp1,temp2);
=======
            if(check(sc[mid],x))l=mid;
            else r=mid;
        }
        int temp1=abs(sc[l]-x);
        int temp2=abs(sc[l+1]-x);
        if(x<sc[1])ans+=sc[1]-x;
        else ans+=min(temp1,temp2);
>>>>>>> 910700d7e6c08f10eaba22dc51f3fd35dfed6e15
    }
    cout<<ans;
    return 0;
}