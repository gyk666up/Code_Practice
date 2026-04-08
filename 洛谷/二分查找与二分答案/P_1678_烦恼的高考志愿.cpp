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

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
#define int long long
int a[N];
int m,n;
bool check(int x,int y)
{
    if(x<=y)return true;
    return false;
}
signed main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)cin>>a[i];
    sort(a+1,a+1+m);
    //找最后一个<=x
    int ans=0;
    while(n--)
    {
        int x;cin>>x;
        int l=0,r=m+1;
        while(l+1!=r)
        {
            int mid=(l+r)/2;
            if(check(a[mid],x))l=mid;
            else r=mid;

        }
        //注意两种极端情况，一种x比所有分数都小，另一种x比所有分数都大
        if(x<a[1])ans+=a[1]-x;//假设所有学校分数都比学生 $x$ 低。推演：二分结束后，l 会指向 $m$（最后一个学校）。此时 l+1 就是 $m+1$。问题：在全局变量中，a[m+1] 的默认值是 0。后果：a[m+1] - x 会变成一个非常小的负数，min 函数会毫不犹豫地选中这个负数，导致你的总分算错。 所以第二项我们取了个abs
        else ans+=min(abs(a[l]-x),abs(a[l+1]-x));
    }
    cout<<ans;
    return 0;
}