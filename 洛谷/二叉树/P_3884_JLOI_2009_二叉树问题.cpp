// // //向根节点的边就是方向向上的边 向叶节点的边就是向下的边
// // //怎么来区分是向上的边 还是向下的边


// // //方法一 使用Floyd算法
// // //树是一种特殊的图 没有环路 一定联通
// // //将父亲到孩子的距离设成1 孩子到父亲的距离设成2 ！！！很聪明
// // #include<bits/stdc++.h>
// // using namespace std;
// // int g[102][102];
// // int level_count[102];//记录每层的节点数 后续计算宽度用
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     int n;cin>>n;
// //     memset(g,0x3f,sizeof g);
// //     for(int i=1;i<=n;i++)g[i][i]=0;
// //     //这里不是n条边 而是n-1条边
// //     for(int i=1;i<=n-1;i++)
// //     {
// //         int u,v;cin>>u>>v;
// //         g[u][v]=1;
// //         g[v][u]=2;
// //     }
// //     //两点之间的距离
// //     for(int k=1;k<=n;k++)
// //     {
// //         for(int i=1;i<=n;i++)
// //         {
// //             if(i!=k)
// //             {
// //                 for(int j=1;j<=n;j++)
// //                 {
// //                     if(j!=k&&j!=i&&g[i][j]>g[i][k]+g[k][j])
// //                     g[i][j]=g[i][k]+g[k][j];
// //                 }
// //             }
// //         }
// //     }
// //     int u,v;cin>>u>>v;
// //     int Max_depth=0;
// //     int Max_level=0;//最大宽度
// //     //深度 每个点到i点的距离
////      这个很聪明的做法
// //     for(int i=2;i<=n;i++)
// //     {
// //         int depth=g[1][i];//注意不能写成g[i][1]因为孩子到父亲权值已经被设置成2了
// //         Max_depth=max(depth,Max_depth);
// //         level_count[depth]++;//该深度的结点数+1
// //         Max_level=max(Max_level,level_count[depth]);
// //     }
// //     cout<<Max_depth+1<<endl<<Max_level<<endl;
// //     cout<<g[u][v]<<endl;

// //     return 0;
// // }


//另一种思路 dfs求深度和宽度 bfs求距离
// #include<bits/stdc++.h>
// using namespace std;
// int n,x,y;
// const int N=200;
// struct node
// {
//     int left,right,fa,depth;
// }dat[N];
// int Max_depth,width[N],Max_width;//数组是记录同一深度结点的个数 个数也就是宽度
// int visited[N];
// void dfs(int u)
// {
//     if(visited[u])return;

//     visited[u]=1;
//     int left=dat[u].left,right=dat[u].right,depth=dat[u].depth;
//     Max_depth=max(Max_depth,depth);
//     width[depth]++;
//     if(left)
//     {
//         dat[left].depth=depth+1;
//         dfs(left);
//     }
//     if(right)
//     {
//         dat[right].depth=depth+1;
//         dfs(right);
//     }
// }
// struct node2
// {
//     int pos,step;
// };
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     //如果u的左孩子是空的话 v就当做左孩子否则就是右孩子
//     for(int i=1;i<=n-1;i++)
//     {
//         int u,v;cin>>u>>v;
//         if(!dat[u].left)dat[u].left=v;
//         else dat[u].right=v;
//         dat[v].fa=u;
//     }
//     cin>>x>>y;
//     dat[1].depth=1;
//     dfs(1);
//     for(int i=1;i<=n;i++)
//     Max_width=max(Max_width,width[i]);
//     cout<<Max_depth<<endl<<Max_width<<endl;

//     memset(visited,0,sizeof visited);
//     node2 t={x,0};
//     visited[t.pos]=1;
//     queue<node2>q;
//     q.push(t);
//     while(q.size())
//     {
//         node2 t=q.front();q.pop();
//         if(t.pos==y)
//         {
//             cout<<t.step;
//             break;
//         }

//         int left=dat[t.pos].left,right=dat[t.pos].right,fa=dat[t.pos].fa,step=t.step;
//         if(left&&!visited[left])//有左孩子 并且没有被访问过
//         {
//             visited[left]=1;
//             q.push({left,step+1});
//         }
//         if(right&&!visited[right])
//         {
//             visited[right]=1;
//             q.push({right,step+1});
//         }
//         if(fa&&!visited[fa])
//         {
//             visited[fa]=1;
//             q.push({fa,step+2});//注意这里的距离
//         }

//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
const int N=1e2+11;
bool visited[N];
struct node
{
    int fa,left,right,depth;
}dat[N];
int n;
int Max_depth,Max_width,width[N];
void dfs(int x)
{
    if(visited[x])return;

    visited[x]=1;
    int left=dat[x].left,right=dat[x].right,depth=dat[x].depth;
    Max_depth=max(Max_depth,depth);
    width[depth]++;
    if(left&&!visited[left])
    {
        dat[left].depth=depth+1;
        dfs(left);
    }
    if(right&&!visited[right])
    {
        dat[right].depth=depth+1;
        dfs(right);
    }
    return;
}
struct node2
{
    int pos,step;
};
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    int x,y;
    for(int i=1;i<=n-1;i++)
    {
        int u,v;cin>>u>>v;
        if(dat[u].left==NULL)dat[u].left=v;
        else dat[u].right=v;
        dat[v].fa=u;
    }
    cin>>x>>y;
    dat[1].depth=1;
    dfs(1);
    for(int i=1;i<=n;i++)Max_width=max(Max_width,width[i]);
    cout<<Max_depth<<endl<<Max_width<<endl;

    memset(visited,0,sizeof visited );
    node2 t={x,0};
    queue<node2>q;
    q.push(t);
   
    visited[t.pos]=1;
    while(q.size())
    {
        auto t=q.front();q.pop();
        if(t.pos==y)
        {
            cout<<t.step<<endl;
            break;
        }

        int left=dat[t.pos].left,right=dat[t.pos].right,fa=dat[t.pos].fa,step=t.step;
        if(left&&!visited[left])
        {
            visited[left]=1;
            q.push({left,step+1});
        }
         if(right&&!visited[right])
        {
            visited[right]=1;
            q.push({right,step+1});
        }
         if(fa&&!visited[fa])
        {
            visited[fa]=1;
            q.push({fa,step+2});
        }
    }
    return 0;
}
