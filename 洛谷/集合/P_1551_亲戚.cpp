// // 第一个想法可以用并查集来做
// // 并查集模板记得不是很清楚了 但还是想起来了 哈哈哈哈
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4;
// int n,m,p;
// int fa[N];
// int find(int x)
// {
//     if(fa[x]!=x)
//      return fa[x]=find(fa[x]);
//     else return x;
// }
// void merge(int x,int y)
// {
//     int xx=find(x),yy=find(y);
//     if(xx!=yy)
//     fa[yy]=xx;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>p;
//     for(int i=1;i<=n;i++)fa[i]=i;//并查集初始化
//     //将输入的第一个人作为父节点 也就是根节点
//     for(int i=1;i<=m;i++)
//     {
//         int u,v;cin>>u>>v;
//         merge(u,v);
//     }
//     while(p--)
//     {
//         int u,v;cin>>u>>v;
//         if(find(u)==find(v))cout<<"Yes\n";
//         else cout<<"No\n";
//     }
//     return 0;
// }

// //但这一章是集合 题解也是并查集
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
int n,m,p;
const int N=5e3+11;
int fa[N];
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int xx=find(x),yy=find(y);
    if(xx==yy)return ;
    fa[yy]=xx;
}
int  main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++)fa[i]=i;
    //while(m--)
    for(int i=0;i<m;i++)
    {
        int x,y;cin>>x>>y;

        merge(x,y);
    }
    for(int i=0;i<p;i++)
    {
        int x,y;cin>>x>>y;
       // if(fa[x]==fa[y])cout<<"Yes\n";
       if(find(x)==find(y))cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}