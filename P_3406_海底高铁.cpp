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



//以上是我自己的思路（😊）不过有些超时，用差分来优化
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
#define int long long
struct node
{
    int A,B,C;
    int cnt;
}edge[N];
int path[N];
int diff[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>path[i];
    for(int i=1;i<=n-1;i++)cin>>edge[i].A>>edge[i].B>>edge[i].C;

    for(int i=1;i<=m-1;i++)
    {
        int city1=path[i],city2=path[i+1];
        if(city1>city2)swap(city1,city2);//这种写法比上面的简洁很多
        // for(int i=city1;i<=city2-1;i++)
        // {
        //     edge[i].cnt++;
        // }
        //city1边到city2-1边都加一
        diff[city1]++;
        diff[city2]--;
    }
    for(int i=1;i<=n-1;i++)edge[i].cnt=edge[i-1].cnt+diff[i];
    int ans=0;
    for(int i=1;i<=n-1;i++)
    {
        int cost1=edge[i].C+edge[i].cnt*edge[i].B;
        int cost2=edge[i].A*edge[i].cnt;
        if(cost1<cost2)ans+=cost1;
        else ans+=cost2;
    }
    cout<<ans;
    return 0;
}