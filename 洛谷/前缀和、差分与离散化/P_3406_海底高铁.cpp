// //当Ci+n*Bi<n*Ai的时候应该买卡，我的思路 统计每一段路经过的次数
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long //注意数据的范围
// const int N=1e5+66;
// struct node
// {
//     int A,B,C;
//     int a,b;//起始点 终止点
//     int cnt;//经过的次数
// }edge[N];   
// int path[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m;cin>>n>>m;
//     for(int i=1;i<n;i++)edge[i].a=i,edge[i].b=i+1;
//     for(int i=1;i<=m;i++)cin>>path[i];
//     for(int i=1;i<=n-1;i++)
//     {
//         cin>>edge[i].A>>edge[i].B>>edge[i].C;
//     }
//     for(int i=1;i<=m-1;i++)
//     {
//         int a=path[i];int b=path[i+1];//这里的a和b指的是城市编号
//         if(a<b)
//         {
//             for(int i=a;i<=b-1;i++)//这里是边的编号 城市1->2这条边的编号为1
//             {
//                 edge[i].cnt++;
//             }
//         }
//         else
//         {
//             for(int i=b;i<=a-1;i++)edge[i].cnt++;
//         }
//     }
//     int ans=0;
//     for(int i=1;i<=n-1;i++)
//     {
//         if(edge[i].C+edge[i].cnt*edge[i].B<edge[i].cnt*edge[i].A)ans+=edge[i].C+edge[i].cnt*edge[i].B;
//         else ans+=edge[i].cnt*edge[i].A;
//     }
//     cout<<ans;
//     return 0;
// }



// //以上是我自己的思路（😊）不过有些超时，用差分来优化
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// #define int long long
// struct node
// {
//     int A,B,C;
//     int cnt;
// }edge[N];
// int path[N];
// int diff[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m;cin>>n>>m;
//     for(int i=1;i<=m;i++)cin>>path[i];
//     for(int i=1;i<=n-1;i++)cin>>edge[i].A>>edge[i].B>>edge[i].C;

//     for(int i=1;i<=m-1;i++)
//     {
//         int city1=path[i],city2=path[i+1];
//         if(city1>city2)swap(city1,city2);//这种写法比上面的简洁很多
//         // for(int i=city1;i<=city2-1;i++)
//         // {
//         //     edge[i].cnt++;
//         // }
//         //city1边到city2-1边都加一
//         diff[city1]++;
//         diff[city2]--;
//     }
//     for(int i=1;i<=n-1;i++)edge[i].cnt=edge[i-1].cnt+diff[i];
//     int ans=0;
//     for(int i=1;i<=n-1;i++)
//     {
//         int cost1=edge[i].C+edge[i].cnt*edge[i].B;
//         int cost2=edge[i].A*edge[i].cnt;
//         if(cost1<cost2)ans+=cost1;
//         else ans+=cost2;
//     }
//     cout<<ans;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// struct node
// {
//     int A,B,C;
//     int cnt;
// }dat[N];
// int path[N];
// int diff[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m;cin>>n>>m;
//     for(int i=1;i<=m;i++)cin>>path[i];
//     for(int i=1;i<=n-1;i++)
//     {
//         cin>>dat[i].A>>dat[i].B>>dat[i].C;
//     }
//     for(int i=1;i<=m-1;i++)
//     {
//         int a=path[i],b=path[i+1];
//         if(a>b)swap(a,b);
//         //编号从a到b-1点边都+1
//         diff[a]++;
//         diff[b]--;
//     }
//     int ans=0;
//     for(int i=1;i<=n-1;i++)
//     {
//         dat[i].cnt=dat[i-1].cnt+diff[i];
//         int n=dat[i].cnt;
//         int cost1=dat[i].B*n+dat[i].C;
//         int cost2=dat[i].A*n;
//         if(cost1<cost2)ans+=cost1;
//         else ans+=cost2;
//     }
//     cout<<ans;
//     return 0;
// }



// //2026/1/23.  这道题还不熟
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,m;
// const int N=1e5+22;
// int path[N];
// int diff[N];
// struct edge
// {
//     int A,B,C;
//     int cnt;//这条边经过几次
// }dat[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=m;i++)cin>>path[i];
//     for(int i=1;i<=n-1;i++)
//     {
//         cin>>dat[i].A>>dat[i].B>>dat[i].C;
//     }
//     for(int i=1;i+1<=m;i++)
//     {
//         int a=path[i],b=path[i+1];
//         //1-3城市1->2 +1  2->3 +1
//         //也就是边a到b-1加1
//         if(a<b)
//         {
//             diff[a]++;//a和b是路的编号
//             //diff[b+1]--;
//             diff[b]--;
//         }
//         else
//         {
//             swap(a,b);
//             diff[a]++;
//            // diff[b+1]--;
//            diff[b]--;
//         }
//     }

//     int ans=0;
//     for(int i=1;i<=n-1;i++)
//     {
//         dat[i].cnt=dat[i-1].cnt+diff[i];

//         int cost1=dat[i].cnt*dat[i].A;
//         int cost2=dat[i].cnt*dat[i].B+dat[i].C;
//         if(cost1<cost2)ans+=cost1;
//         else ans+=cost2;
//     }
//     cout<<ans;
    
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+66;
int path[N];
struct edge
{
    int a,b,c;
    int cnt;
}dat[N];
int n,m;
int diff[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>path[i];

    for(int i=1;i<=n-1;i++)
    {
        cin>>dat[i].a>>dat[i].b>>dat[i].c;
    }

    for(int i=1;i+1<=m;i++)
    {
        int A=path[i],B=path[i+1];
        if(A>B)swap(A,B);

        diff[A]++;
        diff[B]--;
    }
    int ans=0;
    for(int i=1;i<=n-1;i++)
    {
        dat[i].cnt=dat[i-1].cnt+diff[i];
        int n=dat[i].cnt;
        int cost1=n*dat[i].a;
        int cost2=n*dat[i].b+dat[i].c;
        ans+=min(cost1,cost2);
    }

    cout<<ans;
    return 0;
}