// #include<bits/stdc++.h>
// using namespace std;
// int n,c;
// const int N=2e5+11;
// int a[N];
// int b[3];//保存a和b
// bool st[N];
// int cnt=0;
// void dfs(int x,int k)
// {
//     if(x>n)
//     {
//         if(k==2)
//         {
//             int id=0;
//             for(int i=1;i<=n;i++)
//             {
//                 if(st[i])b[++id]=a[i];
//             }
//             //注意这个细节
//             if(b[1]-b[2]==c||b[2]-b[1]==c)cnt++;
//         }
//         return ;
//     }

//     //对于x位置上的数 选和不选
//     st[x]=1;
//     dfs(x+1,k+1);

//     st[x]=0;
//     dfs(x+1,k);

// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>c;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     //先暴力求解
//     //n个数选两个数 满足 a-b=c
//     dfs(1,0);
//     cout<<cnt;
//     return 0;
// }


// //这个做法确实很秒啊
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,c;
// const int N=2e5+11;
// int a[N];
// map<int,int>mp;//统计数字出现的次数
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>c;
//     int ans=0;
//     //将A-B=C->A-C=B
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         mp[a[i]]++;
//         a[i]-=c;
//     }
//     for(int i=1;i<=n;i++)ans+=mp[a[i]];
//     cout<<ans<<endl;
//     return 0;
// }

// //二分
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,c;
// const int N=2e5+11;
// int a[N];
// //第一个大于等于key
// int S1(int x)
// {
//     int l=0,r=n+1;
//     while(l+1!=r)
//     {
//         int mid=(l+r)/2;
//         if(a[mid]<x)
//         l=mid;
//         else r=mid;
//     }
//     return r;
//     //刚开始是这样写的 不对！ 还是有点困惑
//     //因为这样的r有可能越界 导致程序读取随机值 最终导致结果出错
//     // if(a[r]>=x)return r;
//     // else return -1;
// }   
// int S2(int x)
// {
//     int l=0,r=n+1;
//     while(l+1!=r)
//     {
//         int mid=(l+r)/2;
//         if(a[mid]<=x)
//         l=mid;
//         else r=mid;
//     }
//     return r;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>c;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     int ans=0;
//     sort(a+1,a+1+n);
//     for(int i=1;i<=n;i++)//A=B+C
//     {
//         int key=a[i]+c;
//         //查找有多少个元素等于key== >=key->key(二分)
//         int s1=S1(key);
//         int s2=S2(key);
//         //在s1和s2之间的都是等于key的
//         ans+=s2-s1;
//     }
//     cout<<ans;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,c;
// const int N=2e5+11;
// int a[N];
// bool check1(int num,int x)
// {
//     if(num<x)return true;
//     else return false;
// }
// bool check2(int num,int  x)
// {
//     if(num<=x)return true;
//     else return false;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>c;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     sort(a+1,a+1+n);
//     int ans=0;
//     for(int i=1;i<=n-1;i++)
//     {
//         int key=a[i]+c;//枚举b+c 找合适的a

//         //下面其实直接可以用C++库函数

//     //    // 找第一个>=key
//     //     int l=0,r=n+1;
//     //     while(l+1!=r)
//     //     {
//     //         int mid=(l+r)/2;
//     //         if(check1(a[mid],key))l=mid;
//     //         else r=mid;
//     //     }
        
//     //     int id1=r;

//         //找第一个>key 两者相减就是等于key的数量

//         // l=0,r=n+1;
//         // while(l+1!=r)
//         // {
//         //     int mid=(l+r)/2;
//         //     if(check2(a[mid],key))l=mid;
//         //     else r=mid;
//         // }
//         // int id2=r;
//         // ans+=(id2-id1);

//         int id1=lower_bound(a+1,a+1+n,key)-a;
//         int id2=upper_bound(a+1,a+1+n,key)-a;
//         ans+=id2-id1;
//     }
//     cout<<ans;
//     return 0;
// }

//这个方法更聪明一点
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,c;
const int N=2e5+11;
int a[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>c;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int B=a[i];
        int A=B+c;
         ans+=upper_bound(a+1,a+1+n,A)-lower_bound(a+1,a+1+n,A);
    }
    cout<<ans;
    return 0;
}