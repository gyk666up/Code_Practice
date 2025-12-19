//之前做过的题
//第一种方法 dfs 不熟

//有3个点t了
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,c;
//const int N=2e5+11;
// int a[N];
// int b[4];
// int ans=0;
//k这个参数其实就没有用到
// void dfs(int x,int k,int start)
// {
//     if(x>2)
//     {
//         if(b[2]-b[1]==c||b[1]-b[2]==c)ans++;
//         return;
//     }
//     for(int i=start;i<=n;i++)
//     {
//         b[x]=a[i];
//         dfs(x+1,k+1,i+1);
//     }

// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>c;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     dfs(1,0,1);
//     cout<<ans;
// }


// //另一种dfs 这种暴力只能过两个点
// #include<bits/stdc++.h>
// using namespace std;
// int n,c;
// #define int long long
// const int N=2e5+11;
// bool st[N];
// int a[N];
// int b[N];
// int ans=0;
// void dfs(int x,int k)
// {
//     if(x>n)
//     {
//         if(k==2)
//         {
//             int id=0;
//             for(int i=1;i<=n;i++)
//             {
//                 if(st[i])
//                 b[++id]=a[i];
//             }
//             if(b[1]-b[2]==c||b[2]-b[1]==c)ans++;
//         }
//         return ;
//     }
//     st[x]=1;
//     dfs(x+1,k+1);

//     st[x]=0;
//     dfs(x+1,k);
//     return;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>c;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     dfs(1,0);
//     cout<<ans;
//     return 0;
// }

// //正解
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// map<int,int>mp;//统计某个数字有多少个
// int ans=0;
// const int N=2e5+11;
// int a[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,c;cin>>n>>c;

//     //有点绕但很巧妙
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];//此时是将a[i]看作A B=A-C
//         // a[i]-=c;
//         // mp[a[i]-c]++;

//         a[i]+=c; //此时是将a[i]看成B  A=B+C
//         mp[a[i]+c]++;
//     }
//     for(int i=1;i<=n;i++)ans+=mp[a[i]];
//     cout<<ans;
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,c;
const int N=2e3+11;
int a[N];
bool st[N];
int b[3];
int ans=0;
// void dfs(int x,int k)
// {
//     if(x>n)
//     {
//         if(k==2)
//         {
//             int id=0;
//             for(int i=1;i<=n;i++)if(st[i])b[++id]=a[i];
//             if(b[1]-b[2]==c||b[2]-b[1]==c)ans++;
//         }
//         return;
//     }

//     st[x]=1;
//     dfs(x+1,k+1);

//     st[x]=0;
//     dfs(x+1,k);
//     return;
// }
void dfs(int x,int start,int k)
{
    if(x>2)
    {
        if(k==2)
        {
            if(b[1]-b[2]==c||b[2]-b[1]==c)ans++;
        }
        return;
    }
    for(int i=start;i<=n;i++)
    {
        b[x]=a[i];
        dfs(x+1,i+1,k+1);
    }
    return;


}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>c;
    for(int i=1;i<=n;i++)cin>>a[i];
    //dfs(1,0);
    dfs(1,1,0);
    cout<<ans;
    return 0;
}
