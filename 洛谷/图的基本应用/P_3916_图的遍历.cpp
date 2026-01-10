//这样卡了一个点
// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// const int N=1e5+66;
// int a[N];//用于记录点所能到达的最大值
// vector<int>g[N];
// bool st[N];
// int ans=0;
// void bfs(int x)
// {
//     st[x]=1;
//     queue<int>q;
//     q.push(x);
//     while(q.size())
//     {
//         int x=q.front();q.pop();
//         if(ans<x)ans=x;
//         //ans=max(ans,x);
//         for(int i=0;i<g[x].size();i++)
//         {
//             int y=g[x][i];
//             if(!st[y])
//             {
//                 st[y]=1;
//                 q.push(y);
//             }
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)a[i]=i;//每个点肯定能到达自己
//     for(int i=0;i<m;i++)
//     {
//         int u,v;cin>>u>>v;
//         g[u].push_back(v);
//     }
//     //对每一个点bfs或者dfs
//     for(int i=1;i<=n;i++)
//     {
//         if(i==n)continue;
//         ans=0;//记录每个点能到达的最大点
//         memset(st,0,sizeof st);
//         bfs(i);
//         a[i]=max(a[i],ans);
//     }
//     a[n]=n;
//     for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//     return 0;
// }


// //这道题得用反向建边
// //从大到小枚举目标点 M，在反向图上做 BFS，把所有“能到达 M 的点”一次性标记，它们的最大可达点就是 M。
// //贪心思想
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+66;
// vector<int>g[N];
// int n,m;
// int a[N];
// bool st[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)a[i]=i;
//     for(int i=0;i<m;i++)
//     {
//         int u,v;cin>>u>>v;
//         g[v].push_back(u);//反向建边
//     }
//     for(int x=n;x>=1;x--)
//     {
//         if(st[x])continue;

//         st[x]=1;
//         queue<int>q;
//         q.push(x);
//         //a[x]=x;
//         while(q.size())
//         {
//             int x=q.front();q.pop();
//             for(int i=0;i<g[x].size();i++)
//             {
//                 int y=g[x][i];
//                 if(!st[y])
//                 {
//                     a[y]=a[x];
//                     st[y]=1;
//                     q.push(y);
//                 }
//             }
//         }
//     }
//     for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
int n,m;
vector<int>g[N];
int a[N];//记录每个点能到达的编号最大的点
bool st[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;cin>>u>>v;
        //g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)a[i]=i;
    for(int max_id=n;max_id>=1;max_id--)
    {
        if(st[max_id]==0)
        {
            st[max_id]=1;
            a[max_id]=max_id;//每个点至少可以访问到自己
            queue<int>q;
            q.push(max_id);
            while(q.size())
            {
                int x=q.front();q.pop();
                for(int i=0;i<g[x].size();i++)
                {
                    int y=g[x][i];
                    if(!st[y])
                    {
                        st[y]=1;
                        //a[y]=a[x];//或者a[y]=max_id;
                        a[y]=max_id;
                        q.push(y);
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";

    return 0;
}