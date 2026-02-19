// #include <bits/stdc++.h>
// using namespace std;

// struct Edge {
//     int u, v, w;
//     bool operator<(const Edge& other) const {
//         return w < other.w;
//     }
// };

// const int N = 5000 + 5;
// int fa[N];

// int find(int x) {
//     if (fa[x] == x) return x;
//     return fa[x] = find(fa[x]); // 路径压缩
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m;
//     cin >> n >> m;

//     vector<Edge> edges(m);
//     for (int i = 0; i < m; i++) {
//         cin >> edges[i].u >> edges[i].v >> edges[i].w;
//     }

//     // 1. 初始化并查集
//     for (int i = 1; i <= n; i++) fa[i] = i;

//     // 2. 边排序
//     sort(edges.begin(), edges.end());

//     long long ans = 0;
//     int cnt = 0;

//     // 3. Kruskal
//     for (auto &e : edges) {
//         int fu = find(e.u);
//         int fv = find(e.v);
//         if (fu != fv) {
//             fa[fu] = fv;
//             ans += e.w;
//             cnt++;
//             if (cnt == n - 1) break;
//         }
//     }

//     // 4. 判断是否连通
//     if (cnt == n - 1) cout << ans;
//     else cout << "orz";

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// const int N=2e5+11;
// struct Edge
// {
//     int x,y,w;
//     bool operator<(const Edge u)
//     {
//         return w<u.w;
//     }
// };
// //vector<Edge>edge;
// int fa[N];
// int find(int x)
// {
//     if(x==fa[x])return x;
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
//     cin>>n>>m;
//     //vector不预先分配内存，直接这样的话会导致内存崩溃，！！！
//     vector<Edge>edge(m);
//     for(int i=0;i<m;i++)
//     {
//         cin>>edge[i].x>>edge[i].y>>edge[i].w;
//     }
//     //这是普通数组的
//     //sort(edge,edge+m);
//     sort(edge.begin(),edge.end());
//     int ans=0;
//     for(int i=1;i<=n;i++)fa[i]=i;
//     int cnt=0;
//     for(int i=0;i<m;i++)
//     {
//         int x=edge[i].x;
//         int y=edge[i].y;
//         if(find(x)!=find(y))
//         {
//             merge(x,y);
//             ans+=edge[i].w;
//             cnt++;
//         }
//         if(cnt==n-1)break;
//     }
//     if(cnt!=n-1)cout<<"orz";
//     else cout<<ans;
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// struct Edge
// {
//     int x,y,w;
//     bool operator<(const Edge&u)
//     {
//         return w<u.w;
//     }
// };
// const int N=5e3+11;
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
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)fa[i]=i;
//     vector<Edge>edge(m);
//     for(int i=0;i<m;i++)
//     {
//         cin>>edge[i].x>>edge[i].y>>edge[i].w;
//     }
//     sort(edge.begin(),edge.end());

//     int ans=0;
//     int cnt=0;
//     for(int i=0;i<m;i++)
//     {
//         int x=edge[i].x,y=edge[i].y,w=edge[i].w;
//         if(find(x)!=find(y))
//         {
//             merge(x,y);
//             ans+=w;
//             cnt++;
//         }
//         //if(cnt==n-1)break;为什么这行代码不写也没出错呢
//         //一旦你已经选满 n-1 条边：整个图已经连通,所有点的 find(x) 都相等,后面的边全部都会被 if 拦下来
//     }
//     if(cnt!=n-1)cout<<"orz";
//     else cout<<ans;
    

//     return 0;
// }


