// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// vector<int>g[N];
// bool st[N];
// int root;
// void dfs(int x)
// {
//     st[x]=1;
//     cout<<x<<" ";
//     if(g[x].size()==0)
//     {
//         return;
//     }
//     for(int i=0;i<g[x].size();i++)
//     {
//         if(!st[g[x][i]])
//         dfs(g[x][i]);
//     }
//     return ;
// }
// void bfs(int x)
// {
//     queue<int>q;
//     q.push(x);
//     st[x]=1;
//     while(q.size())
//     {
//         int t=q.front();q.pop();
//         cout<<t<<" ";
//         for(int i=0;i<g[t].size();i++)
//         {
//             int j=g[t][i];
//             if(!st[j])
//             {
//                 st[j]=1;
//                 q.push(j);
//             }
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m;cin>>n>>m;
//     for(int i=1;i<=m;i++)
//     {
//         int u,v;cin>>u>>v;
//         //st[v]=1;
//         g[u].push_back(v);
//     }
//     //sort(g->begin(),g.end());
//     //注意这个排序
//     for(int i=1;i<=n;i++)sort(g[i].begin(),g[i].end());
//     //找入口
//     // for(int i=1;i<=n;i++)
//     // {
//     //     if(!st[i])root=i;
//     // }
//     //题目要求的是编号为1的开始遍历
//     memset(st,0,sizeof st);
//     st[root]=1;
//     dfs(1);
//     cout<<endl;
//     memset(st,0,sizeof st);
//     bfs(1);
//     return 0;
// }





// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// const int N=1e5+11;
// vector<int>g[N];
// bool st[N];
// void dfs(int x)
// {
//     cout<<x<<" ";
//     if(!g[x].size())
//     {
//         return ;
//     }
//     for(int i=0;i<g[x].size();i++)
//     {
//         int v=g[x][i];
//         if(!st[v])
//         {
//             st[v]=1;
//             dfs(v);
//         }
       
//     }
//     return;
// }
// void bfs(int x)
// {
//     queue<int>q;
//     q.push(x);
//     st[x]=1;
//     while(q.size())
//     {
//         int u=q.front();q.pop();
//         cout<<u<<" ";
//         for(int i=0;i<g[u].size();i++)
//         {
//             int v=g[u][i];
//             if(!st[v])
//             {
//                 st[v]=1;
//                 q.push(v);
//             }
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=0;i<m;i++)
//     {
//         int u,v;cin>>u>>v;
//         g[u].push_back(v);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         sort(g[i].begin(),g[i].end());
//     }
//     st[1]=1;//这一行代码别忘记！！！
//     dfs(1);
//     cout<<endl;
//     memset(st,0,sizeof st);
//     bfs(1);
//     return 0;
// }


//2026/1/9
#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e5+11;
vector<int>g[N];
bool st[N];
void dfs(int x)
{
    st[x]=1;
    if(x==1)cout<<x;
    else cout<<" "<<x;
    
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i];
        if(!st[y])
        {
            dfs(y);
        }
    }
}
void bfs(int x)
{
    memset(st,0,sizeof st);
    st[x]=1;
    queue<int>q;
    q.push(x);
    while(q.size())
    {
        int x=q.front();q.pop();
        if(x==1)cout<<x;
        else cout<<" "<<x;
        for(int i=0;i<g[x].size();i++)
        {
            int y=g[x][i];
            if(st[y]==0)
            {
                st[y]=1;
                q.push(y);
            }
        }
        
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;cin>>x>>y;
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
    {
        sort(g[i].begin(),g[i].end());
    }
    dfs(1);
    cout<<endl;
    bfs(1);
    return 0;
}