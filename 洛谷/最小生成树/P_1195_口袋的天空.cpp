// //要把所有云朵连成 K 个棉花糖，就是说并查集有K个祖先
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3+11;
// int n,m,k;
// struct Edge
// {
//     int x,y,w;
//     bool operator<(const Edge&u)
//     {
//         return w<u.w;
//     }
// };
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
//     cin>>n>>m>>k;
//     for(int i=1;i<=n;i++)fa[i]=i;
//     vector<Edge>edge(m);
//     for(int i=0;i<m;i++)
//     {
//         cin>>edge[i].x>>edge[i].y>>edge[i].w;
//     }
//     sort(edge.begin(),edge.end());

//     int ans=0;
//     //int cnt=0; 定义到里面
//     //这个点谁能想到啊
//     if(n==k)
//     {
//         cout<<0;
//         return 0;
//     }
//     int block=n;
//     for(int i=0;i<m;i++)
//     {
//         int x=edge[i].x,y=edge[i].y,w=edge[i].w;
//         if(find(x)!=find(y))
//         {
//             merge(x,y);
//             ans+=w;
//             block--;//这种方法更聪明
//         }
//         int cnt=0;
//         //这种复杂度高
//         // for(int i=1;i<=n;i++)
//         // {
//         //     if(fa[i]==i)cnt++;
//         // }
//         if(block==k)
//         {
//             cout<<ans;
//             return 0;
//         }
//     }
//     cout<<"No Answer";
//     return 0;
// }
