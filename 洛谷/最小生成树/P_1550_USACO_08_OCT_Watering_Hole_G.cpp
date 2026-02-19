// //秒了哈哈哈哈哈
// //跟之前的买礼物这道题简直一模一样
// #include<bits/stdc++.h>
// using namespace std;
// struct Edge
// {
//     int x,y,w;
//     bool operator<(const Edge&u)
//     {
//         return w<u.w;
//     }
// };
// int n;
// const int N=500;
// int fa[N];
// int find(int x)
// {
//     if(fa[x]==x)return x;
//     return fa[x]=find(fa[x]);
// }
// void merge(int x,int y)
// {
//     int xx=find(x),yy=find(y);
//     if(xx==yy)return;
//     fa[yy]=xx;
// }

// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)fa[i]=i;
//     vector<Edge>edge;
//     //跟之前的买礼物很像啊，MST+虚拟节点
//     for(int i=1;i<=n;i++)
//     {
//         int x;cin>>x;
//         edge.push_back({0,i,x});
//     }

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             int k;cin>>k;
//             if(i<j)//不引入重复边 主要是为了提高效率 
//             {
//                 edge.push_back({i,j,k});
//             }
//         }
//     }
//     sort(edge.begin(),edge.end());

//     int ans=0;
//     int cnt=0;
//     for(int i=0;i<edge.size();i++)
//     {
//         int x=edge[i].x,y=edge[i].y,w=edge[i].w;
//         if(find(x)!=find(y))
//         {
//             merge(x,y);
//             ans+=w;
//         }
//         if(cnt==n)break;
//     }
//     cout<<ans;

//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int n;
const int N=302;
int fa[N];
struct edge
{
    int x,y,w;
    bool operator<(const edge&u)
    {
        return w<u.w;
    }
};
vector<edge>v;
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
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        v.push_back({0,i,x});
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x;cin>>x;
            if(i<j)
            v.push_back({i,j,x});
        }
    }
    sort(v.begin(),v.end());
    
    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        int x=v[i].x,y=v[i].y,w=v[i].w;
        if(find(x)!=find(y))
        {
            merge(x,y);

            ans+=w;
        }
    }

    cout<<ans;

    return 0;
}