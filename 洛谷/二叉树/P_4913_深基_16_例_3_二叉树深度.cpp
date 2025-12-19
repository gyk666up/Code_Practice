// //直接暴力dfs
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// const int N=1e6+11;
// vector<int>g[N];//记录每个顶点对应的孩子
// int ans=0;
// void dfs(int x,int height)
// {
//     if(g[x].size()==0)//已经到叶子结点了
//     {
//         ans=max(ans,height);
//         return;
//     }
//     for(int i=0;i<g[x].size();i++)
//     {
//         int j=g[x][i];
//         dfs(j,height+1);
//     }
//     return;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         int x,y;cin>>x>>y;
//         if(x!=0)//注意这里的判断语句 如果没有这个判断语句 0 0 也会被当成孩子
//         g[i].push_back(x);
//         if(y!=0)
//         g[i].push_back(y);
//     }
//     dfs(1,1);//根节点的深度为1
//     cout<<ans;
//     return 0;
// }



//优化版->记忆化搜索
#include<bits/stdc++.h>
using namespace std;
int n;
int ans=1;
int son[10000010][3];//son[i][1]表示i的左节点 2表示i的右节点
int mem[10000010];
int dfs(int dep,int now)//dep表示现在搜了多少层，now表示在几号结点
{
    if(mem[now]!=0)return mem[now];
    //if(now==0)return 0;//没有0号结点
    if(son[now][1]!=0||son[now][2]!=0)//如果有孩子
    {
        mem[now]=max(dfs(dep+1,son[now][1]),dfs(dep+1,son[now][2]));
    }
    else
    {
        ans=max(ans,dep);//记录最深的层数
    }
    return dep;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;cin>>a>>b;
        son[i][1]=a;
        son[i][2]=b;
    }
    // for(int i=1;i<=n;i++)dfs(1,i);
    //直接dfs(1,1)就行了 要想最深的话 肯定是从根节点开始
    cout<<ans;
    return 0;
}